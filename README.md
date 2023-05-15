<img src="https://img.shields.io/badge/Made_With_CLion-black?style=for-the-badge&logo=clion&logoColor=green" style="margin-left: 0" alt="Made in the IDE CLion"/>
<img src="https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white" style="margin-left: 5px" alt="Made with C"/>
<img src="https://img.shields.io/badge/Windows_11-0078D6?style=for-the-badge&logo=windows11&logoColor=white" style="margin-left: 5px" alt="Made in Windows 11" />

# Speicherverwaltungssystem
>Speicherverwaltungssoftware mit LinkedLists\
>Diese Projekt simuliert die Funktionsweise eines RAM-Speichers und implementiert vier verschiedene Algorithmen zur Speicherverwaltung:
>  1. FirstFit
>  2. NextFit
>  3. WorstFit
>  4. BestFit

# Inhaltsangabe
 * [Features](#features)
 * [Verwendung mit CLion](#verwendung-mit-clion)
 * [Verwendung ohne CLion](#verwendung-ohne-clion)
 * [Algorithmen](#algorithmen)
 * [Code](#code)

# Features
Menu:
```text
1. Prozess zu Speicher hinzufuegen
2. Prozess aus Speicher loeschen
3. Speicher ausgeben
4. Exit
```

* Hinzufügen von Prozessen zum RAM-Speicher, die grösse kann angegeben werden, der Name des Prozesses ist frei wählbar und man kann zwischen [4 Algorithmen](#algorithmen) aussuchen
* Durch die möglichkeit Prozesse auch wieder zu entfernen, kann der RAM-Speicher besser simuliert werden, das Programm muss nicht beendet werden, um belegten Speicher freizugeben. 
* Man kann sich den RAM-Speicher ausgeben lassen, und kann somit feststellen, ob die Simulation korrekt funktioniert 
* Durch das Beenden mit einem "Clean-Up" (mit der funktion `free()` wird die Liste de-allokiert) können sogenannte Memory-Leaks verhindert werden

# Verwendung mit CLion
  1. Um das Projekt verwenden zu können muss es ([Speicherverwaltung](https://github.com/Nphilip9/Speicherverwaltung/)) zunächst heruntergeladen und entpackt werden.
  2. Öffnen Sie das Projekt in CLion
  3. Betätigen Sie den Button `Run`

# Verwendung ohne CLion
  1. Um das Projekt verwenden zu können muss es ([Speicherverwaltung](https://github.com/Nphilip9/Speicherverwaltung/)) zunächst heruntergeladen und entpackt werden.
  2. Öffnen Sie den Terminal und Navigieren Sie zum Pfad `Speicherverwaltung-main/src`
  3. Erstellen Sie die ausführbare Datei mit den Befehl `gcc main.h main.c -o Speicherverwaltung.exe`
  4. Führen Sie die Datei `Speicherverwaltung.exe` mit dem Befehl `start Speicherverwaltung.exe` oder durch einen Doppelklick auf die Datei

# Algorithmen
| Algorithmus                    | Beschreibung                                                                                                 |
|:-------------------------------|:-------------------------------------------------------------------------------------------------------------|
| [`First Fit`](src/main.c#L136) | Sucht den ersten freien Speicherplatz der gross genug ist                                                    |
| [`Next Fit`](src/main.c#L153)  | Sucht ab dem zuletzt verwendeten Speicherblock den nächsten verfügbaren Speicherplatz für einen neuen Block. |
| [`Best Fit`](src/main.c#L181)  | Sucht die kleinst mögliche lücke die gleich gross oder größer ist als der angeforderte Speicher              |
| [`Worst Fit`](src/main.c#L210) | Sucht den größtmöglichen freien Speicherplatz                                                                |

# Code
Diese Zeile kann verändert werden um den simulierten RAM-Speicher zu vergrössern oder zu verkleinern.
#### [main.h](src/main.h#L9)
```C
#define MEMORY_SIZE 64
```
Diese Zeile kann verändert werden, um die Maximale länge festzulegen, die der Name eines Prozesses haben darf.
#### [main.h](src/main.h#L10)
```C
#define MAX_PROCESS_NAME_LENGTH 10
```

