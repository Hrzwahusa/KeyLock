# KeyLock

A simple keyboard lock application built with Qt for Windows.

## Description

KeyLock is a Qt-based application that allows users to lock and unlock keyboard input on Windows systems. When locked, it blocks all keyboard events using a low-level Windows hook, providing a way to prevent accidental or unauthorized keyboard input.

## Features

- **Toggle Lock**: Click the button to lock or unlock the keyboard.
- **Visual Feedback**: Displays lock or unlock icons to indicate the current state.
- **Global Hook**: Uses Windows low-level keyboard hook to intercept and block key presses when locked.
- **Simple UI**: Minimalist interface with a large button for easy interaction.

## Requirements

- Windows operating system
- Qt 5 or later (with Qt Widgets)
- C++14 compatible compiler (e.g., Visual Studio 2017+)
- Qt development tools (qmake, moc, etc.)

## Installation

### Option 1: Download Pre-built Release (Recommended)

The easiest way to get started is to download the latest pre-built release:

1. Go to the [Releases page](https://github.com/Hrzwahusa/KeyLock/releases/latest)
2. Download the latest `KeyLock_v_*.zip` file
3. Extract the ZIP file to your desired location
4. Run `KeyLock.exe` from the extracted folder

### Option 2: Build from Source

1. Clone the repository:
   ```
   git clone https://github.com/Hrzwahusa/KeyLock.git
   cd KeyLock
   ```

2. Open the solution file `KeyLock.sln` in Visual Studio with Qt support installed.

3. Ensure Qt paths are configured in Visual Studio (Qt VS Tools).

4. Build the project in Release or Debug configuration.

5. Run the generated executable.

## Usage

- Launch the application.
- The window shows an unlock icon initially.
- Click the button to lock the keyboard: the icon changes to a lock, and all keyboard input is blocked.
- Click again to unlock: the icon changes back, and keyboard input is restored.
- Close the application to exit.

**Note**: When locked, the application must be unlocked from within (e.g., using mouse) as keyboard is disabled.

## Building from Source

- Ensure Qt is installed and configured.
- Use Visual Studio to open and build the project.
- Alternatively, if using Qt Creator, convert the .vcxproj to .pro or create a new .pro file.

## Contributing

Feel free to submit issues or pull requests for improvements.

## License

This project is open source. Please check the license file if available.