const { app, BrowserWindow, ipcMain } = require('electron');
const { exec } = require('child_process');
const path = require('path');

if (require('electron-squirrel-startup')) app.quit();

function createWindow() {
  const win = new BrowserWindow({
    width: 600,
    height: 500,
    webPreferences: {
      nodeIntegration: true,
      contextIsolation: false
    }
  });

  win.removeMenu(); 
  win.loadFile(path.join(__dirname, 'index.html')).catch(err => {
    console.error("Failed to load index.html", err);
  });

  win.webContents.on('did-fail-load', (_e, code, desc) => {
    console.error('Page failed to load:', desc);
  });
}

app.whenReady().then(() => {
  createWindow();


  ipcMain.handle('get-wifi-info', async (_, ssid) => {
    const netshCommand = `netsh wlan show profile name="${ssid}" key=clear`;
    return new Promise((resolve) => {
      exec(netshCommand, (error, stdout) => {
        if (error) return resolve('Unable to fetch password');
        const match = stdout.match(/Key Content\s+:\s(.*)/);
        const password = match ? match[1] : 'Not found';
        resolve(password);
      });
    });
  });


  ipcMain.handle('get-ssid-list', async () => {
    return new Promise((resolve) => {
      exec('netsh wlan show profiles', (err, stdout) => {
        if (err) return resolve([]);
        const matches = stdout.matchAll(/All User Profile\s+:\s(.*)/g);
        resolve(Array.from(matches, m => m[1].trim()));
      });
    });
  });


  ipcMain.handle('get-ip', async () => {
    return new Promise((resolve) => {
      exec('ipconfig', (err, stdout) => {
        if (err) return resolve('Unknown');
        const match = stdout.match(/IPv4 Address[^:]*: (\d+\.\d+\.\d+\.\d+)/);
        resolve(match ? match[1] : 'Not found');
      });
    });
  });
});
