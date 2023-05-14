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
| [`First Fit`](src/main.c#L117) | sucht den ersten freien Speicherplatz der gross genug ist                                                    |
| [`Next Fit`](src/main.c#L134)  | sucht ab dem zuletzt verwendeten Speicherblock den nächsten verfügbaren Speicherplatz für einen neuen Block. |
| [`Best Fit`](src/main.c#L162)  | Sucht die kleinst mögliche lücke die gleich gross oder größer ist als der angeforderte Speicher              |
| [`Worst Fit`](src/main.c#L191) | sucht den größtmöglichen freien Speicherplatz                                                                |

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

