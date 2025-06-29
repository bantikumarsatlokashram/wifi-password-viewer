# WiFi Password Viewer 🛠️
![WiFi Password Viewer UI](https://raw.githubusercontent.com/bantikumarsatlokashram/wifi-password-viewer/main/wifi-password-viewer.png)


A beautiful and lightweight Windows desktop application that allows users to:

- View saved Wi-Fi network names (SSIDs)
- Instantly reveal their stored passwords
- Display the current local IP address

Built using **Electron**, **HTML + Tailwind CSS**, and **Node.js**, this app offers a modern interface with native `.exe` packaging.

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

