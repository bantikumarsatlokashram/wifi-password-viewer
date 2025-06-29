#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <shellapi.h>

std::string RunCommand(const std::string& cmd) {
    char buffer[128];
    std::string result;
    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) return "Error";
    while (fgets(buffer, sizeof buffer, pipe)) result += buffer;
    _pclose(pipe);
    return result;
}

std::vector<std::string> GetWifiProfiles() {
    std::string data = RunCommand("netsh wlan show profiles");
    std::vector<std::string> profiles;
    std::istringstream stream(data);
    std::string line;
    while (std::getline(stream, line)) {
        auto pos = line.find(":");
        if (pos != std::string::npos)
            profiles.push_back(line.substr(pos + 1));
    }
    return profiles;
}

std::string GetPassword(const std::string& profile) {
    std::string cmd = "netsh wlan show profile name=\"" + profile + "\" key=clear";
    std::string result = RunCommand(cmd);
    auto pos = result.find("Key Content");
    if (pos != std::string::npos) {
        auto colon = result.find(":", pos);
        return result.substr(colon + 1, result.find("\n", colon) - colon);
    }
    return "Not found";
}

std::string GetIPAddress() {
    std::string data = RunCommand("ipconfig");
    auto pos = data.find("IPv4 Address");
    if (pos != std::string::npos) {
        auto colon = data.find(":", pos);
        return data.substr(colon + 2, data.find("\n", colon) - colon - 2);
    }
    return "Not found";
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND combo, btn, ipText, pwdText;

    switch (uMsg) {
        case WM_CREATE: {
            CreateWindow("STATIC", "Wi-Fi Password Viewer", WS_VISIBLE | WS_CHILD,
                20, 10, 300, 30, hwnd, NULL, NULL, NULL);

            combo = CreateWindow("COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
                20, 50, 250, 300, hwnd, NULL, NULL, NULL);

            btn = CreateWindow("BUTTON", "Get Password", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                20, 90, 120, 30, hwnd, (HMENU)1, NULL, NULL);

            ipText = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                20, 140, 300, 20, hwnd, NULL, NULL, NULL);

            pwdText = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                20, 170, 300, 20, hwnd, NULL, NULL, NULL);

            auto profiles = GetWifiProfiles();
            for (const auto& p : profiles)
                SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)p.c_str());

            std::string ip = "IP: " + GetIPAddress();
            SetWindowText(ipText, ip.c_str());

            break;
        }
        case WM_COMMAND:
            if (LOWORD(wParam) == 1) {
                char buffer[256];
                SendMessage(combo, CB_GETLBTEXT, SendMessage(combo, CB_GETCURSEL, 0, 0), (LPARAM)buffer);
                std::string pwd = "Password:" + GetPassword(buffer);
                SetWindowText(pwdText, pwd.c_str());
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const char CLASS_NAME[] = "WiFiViewerWindowClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "WiFi Password Viewer",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
