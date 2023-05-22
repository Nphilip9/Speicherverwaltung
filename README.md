<img src="https://img.shields.io/badge/Made_With_CLion-black?style=for-the-badge&logo=clion&logoColor=green" style="margin-left: 0" alt="Made in the IDE CLion"/>
<img src="https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white" style="margin-left: 5px" alt="Made with C"/>
<img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0" style="margin-left: 5px" alt="Compatible MacOS Ventura" />
<img src="https://img.shields.io/badge/Windows_11-0078D6?style=for-the-badge&logo=windows11&logoColor=white" style="margin-left: 5px" alt="Made in Windows 11" />

# Speicherverwaltungssystem
>Speicherverwaltungssoftware mit LinkedLists\
>Diese Projekt simuliert die Funktionsweise eines RAM-Speichers und implementiert vier verschiedene Algorithmen zur Speicherverwaltung:
>  1. FirstFit
>  2. NextFit
>  3. WorstFit
>  4. BestFit

# Inhaltsangabe
 * [Systemanforderungen](#systemanforderungen)
 * [Features](#features)
 * [Automatisiertes starten](#automatisiertes-starten-des-programms)
 * [Verwendung mit JetBrains](#verwendung-mit-jetbrains)
 * [Verwendung ohne JetBrains](#verwendung-ohne-jetbrains)
 * [Algorithmen](#algorithmen)
 * [Code](#code)
   * [Anpassen der Listenlänge](#anpassen-der-listenlänge)
   * [Anpassen der maximal länge des Prozesses](#anpassen-der-maximal-länge-des-prozesses)
   * [Element aus der Liste](#element-aus-der-liste)
 * [Lizenz](#lizenz)

# Systemanforderungen
 * [`C-Compiler`](https://gcc.gnu.org/)
 * [`C99`](https://de.wikipedia.org/wiki/C99#:~:text=C99%20steht%20f%C3%BCr%3A,Dunkelwolke%20aus%20dem%20Caldwell%2DKatalog)
 * Empfohlen: [`CLion`](https://www.jetbrains.com/de-de/clion/)

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

# Automatisiertes starten des Programms
  1. Um das Projekt verwenden zu können muss es ([Speicherverwaltung](https://github.com/Nphilip9/Speicherverwaltung/)) zunächst heruntergeladen und entpackt werden.
  2. Öffnen Sie den Terminal und Navigieren Sie zum Pfad `Speicherverwaltung-main/src`
  3. Starten Sie das Programm `run.bat`

# Verwendung mit JetBrains
  1. Um das Projekt verwenden zu können muss es ([Speicherverwaltung](https://github.com/Nphilip9/Speicherverwaltung/)) zunächst heruntergeladen und entpackt werden.
  2. Öffnen Sie das Projekt in CLion
  3. Betätigen Sie den Button `Run`

# Verwendung ohne JetBrains
  1. Um das Projekt verwenden zu können muss es ([Speicherverwaltung](https://github.com/Nphilip9/Speicherverwaltung/)) zunächst heruntergeladen und entpackt werden.
  2. Öffnen Sie den Terminal und Navigieren Sie zum Pfad `Speicherverwaltung-main/src`
  3. Erstellen Sie die ausführbare Datei mit den Befehl `gcc main.h main.c -o Speicherverwaltung.exe`
  4. Führen Sie die Datei `Speicherverwaltung.exe` mit dem Befehl `start Speicherverwaltung.exe` oder durch einen Doppelklick auf die Datei

# Algorithmen
| Algorithmus                    | Beschreibung                                                                                                 |
|:-------------------------------|:-------------------------------------------------------------------------------------------------------------|
| [`First Fit`](src/main.c#L191) | Sucht den ersten freien Speicherplatz der gross genug ist                                                    |
| [`Next Fit`](src/main.c#L216)  | Sucht ab dem zuletzt verwendeten Speicherblock den nächsten verfügbaren Speicherplatz für einen neuen Block. |
| [`Best Fit`](src/main.c#L258)  | Sucht die kleinst mögliche lücke die gleich gross oder größer ist als der angeforderte Speicher              |
| [`Worst Fit`](src/main.c#L294) | Sucht den größtmöglichen freien Speicherplatz                                                                |

# Code
### Anpassen der Listenlänge
Diese Zeile kann verändert werden um den simulierten RAM-Speicher zu vergrössern oder zu verkleinern.
```C
#define MEMORY_SIZE 64
```
##### [`main.h`](src/main.h#L9)
### Anpassen der maximal länge des Prozesses
Diese Zeile kann verändert werden, um die Maximale länge festzulegen, die der Name eines Prozesses haben darf.
```C
#define MAX_PROCESS_NAME_LENGTH 10
```
##### [`main.h`](src/main.h#L10)

### Element aus der Liste
Die Variable `data` speichert den Inhalt des Prozesses, er wird nur zur simulationszwecken mit einer zufallszahl befüllt.\
Der Name des Prozesses wird in der Variable `name` gespeichert die Länge kann [hier](src/main.h#L12) festgelegt werden.\
Der `next` Pointer zeigt auf das nächste Element in der Liste, sollte es kein nächstes Element geben, ist der Pointer `NULL`.
```C
typedef struct node {
    int data;
    char *name;
    struct node *next;
} NODE;
```
[`main.h`](src/main.h#L12)
# Lizenz
MIT License

Copyright (c) 2023 Neumair Philip

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.