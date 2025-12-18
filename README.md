# KeyLock

Eine einfache Tastatursperre-Anwendung, entwickelt mit Qt für Windows.

## Beschreibung

KeyLock ist eine Qt-basierte Anwendung, die es Benutzern ermöglicht, die Tastatureingabe auf Windows-Systemen zu sperren und freizugeben. Bei gesperrtem Zustand blockiert sie alle Tastaturereignisse mithilfe eines Low-Level-Windows-Hooks und bietet so eine Möglichkeit, versehentliche oder unbefugte Tastatureingaben zu verhindern.

## Funktionen

- **Sperre umschalten**: Klicke auf die Schaltfläche, um die Tastatur zu sperren oder freizugeben.
- **Visuelles Feedback**: Zeigt Sperr- oder Freigabe-Icons an, um den aktuellen Zustand anzuzeigen.
- **Globaler Hook**: Verwendet einen Low-Level-Tastatur-Hook von Windows, um Tastendrücke bei gesperrtem Zustand abzufangen und zu blockieren.
- **Einfache Benutzeroberfläche**: Minimalistische Oberfläche mit einer großen Schaltfläche für einfache Interaktion.

## Anforderungen

- Windows-Betriebssystem
- Qt 5 oder neuer (mit Qt Widgets)
- C++14-kompatibler Compiler (z. B. Visual Studio 2017+)
- Qt-Entwicklungstools (qmake, moc, etc.)

## Installation

1. Repository klonen:
   ```
   git clone https://github.com/Hrzwahusa/KeyLock.git
   cd KeyLock
   ```

2. Öffne die Lösungsdatei `Tastatursperre.sln` in Visual Studio mit installierter Qt-Unterstützung.

3. Stelle sicher, dass Qt-Pfade in Visual Studio konfiguriert sind (Qt VS Tools).

4. Baue das Projekt in Release- oder Debug-Konfiguration.

5. Führe die generierte ausführbare Datei aus.

## Verwendung

- Starte die Anwendung.
- Das Fenster zeigt anfangs ein Freigabe-Icon.
- Klicke auf die Schaltfläche, um die Tastatur zu sperren: Das Icon ändert sich zu einem Schloss, und alle Tastatureingaben werden blockiert.
- Klicke erneut, um freizugeben: Das Icon ändert sich zurück, und Tastatureingaben werden wiederhergestellt.
- Schließe die Anwendung, um zu beenden.

**Hinweis**: Bei gesperrtem Zustand muss die Anwendung von innen freigegeben werden (z. B. mit der Maus), da die Tastatur deaktiviert ist.

## Aus dem Quellcode bauen

- Stelle sicher, dass Qt installiert und konfiguriert ist.
- Verwende Visual Studio, um das Projekt zu öffnen und zu bauen.
- Alternativ, bei Verwendung von Qt Creator, konvertiere die .vcxproj zu .pro oder erstelle eine neue .pro-Datei.

## Mitwirken

Gerne Issues oder Pull Requests für Verbesserungen einreichen.

## Lizenz

Dieses Projekt ist Open Source. Bitte überprüfe die Lizenzdatei, falls vorhanden.