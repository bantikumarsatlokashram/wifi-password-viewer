# WiFi Password Viewer 🛠️
![WiFi Password Viewer UI](https://raw.githubusercontent.com/bantikumarsatlokashram/wifi-password-viewer/main/wifi-password-viewer.png)


A beautiful and lightweight Windows desktop application that allows users to:

- View saved Wi-Fi network names (SSIDs)
- Instantly reveal their stored passwords
- Display the current local IP address

Built using **Electron**, **HTML + Tailwind CSS**, and **Node.js**, this app offers a modern interface with native `.exe` packaging.

---

## 🚀 Releases

The latest version of the WiFi Password Viewer is available as a precompiled `.exe` file for Windows users.

### 📦 Download
👉 [WiFi Password Viewer.exe](https://github.com/bantikumarsatlokashram/wifi-password-viewer/releases/download/v1.0.1/wifi-password-viewer-1.0.0.Setup.exe)

### ✅ How to Use:
1. Download the `.exe` file to your system
2. Double-click to run — no installation needed
3. Grant permission if prompted by Windows SmartScreen
4. Use the app to:
   - Select a saved Wi-Fi network
   - View the password and IP address instantly

> ⚠️ Note: This app reads saved Wi-Fi profiles and passwords using `netsh`, which works on Windows systems only.

---

## 📁 Repository

**GitHub Directory:**\
[https://github.com/bantikumarsatlokashram/wifi-password-viewer](https://github.com/bantikumarsatlokashram/wifi-password-viewer)

---

## ✨ Features

- ✅ View saved Wi-Fi network names
- 🔐 Reveal their stored passwords (Windows only)
- 🌐 Show your current IPv4 address
- 🎨 Beautiful interface using Tailwind CSS
- 📦 One-click `.exe` installer

---

## 🖥️ How to Run (For Developers)

1. **Clone the repository:**

   ```bash
   git clone https://github.com/bantikumarsatlokashram/wifi-password-viewer.git
   cd wifi-password-viewer
   ```

2. **Install dependencies:**

   ```bash
   npm install
   ```

3. **Start the app (development):**

   ```bash
   npm start
   ```

---

## 📦 How to Build `.exe` Installer

> Electron Forge is already configured

1. **Make sure everything is ready:**

   ```bash
   npm run make
   ```

2. The generated `.exe` file will be found at:

   ```
   out/make/squirrel.windows/x64/WiFi Password Viewer Setup.exe
   ```

---

## 📂 Folder Structure

```
wifi-password-viewer/
├── index.html          # Frontend UI with Tailwind CSS
├── main.js             # Electron main process
├── package.json        # App configuration & dependencies
├── forge.config.js     # Electron Forge build config
└── out/                # Generated build and .exe installer
```

---

## 🙏 Credits

Developed by: [Banti Kumar (Satlok Ashram)](https://github.com/bantikumarsatlokashram)

---

## 📃 License

MIT License. Feel free to modify and use.

