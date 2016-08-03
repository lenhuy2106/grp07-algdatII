[![Build Status](https://travis-ci.org/algdat/grp07-algdatII.svg?branch=master)](https://travis-ci.org/algdat/grp07-algdatII)

grp07-algdatII

Github-Pages: https://algdat.github.io/grp07-algdatII/

Doxygen: https://cdn.rawgit.com/algdat/grp07-algdatII/master/html/index.html

# Text-Suche in dynamischen Texten

Implementierung und Vergleich von drei Algorithmen auf Laufzeit.

## Table of Contents

* [Team Members](#team-members)
* [Introduction](#intro)
* [Getting started](#getting-started)
* [Resources](#resources)
* [License](#license)

## <a name="team-members"></a>Team Members
* "Maximilian Keil" (Sweetboi) 
* "Andi Buchmann" (Bookman)
* "Nhu Huy Le" (Boss)
* "Long Mathias Yan" (China)

## <a name="intro"></a>Introduction
Im Rahmen der Vorlesung _Algorithmen und Datenstrukturen 2_ im SS 16 an der Hochschule München entwickeln
und vergleichen wir drei Algorithmen für die Textsuche in dynamischen (veränderlichen) Texten:

* (Unterbrechender) Naiver Algorithmus
* Knuth-Morris-Pratt Algorithmus
* Boyer-Moore-Horspool Algorithmus

### Umfang
- [x] C++-Code in dem Gruppen-GitHub-Repository
- [x] moderner C++-Code (C++11, C++14)

`set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")` 
- [x] Unittests mit “vernünftiger” Code-Abdeckung
- [x] Website für das Projekt inkl. Sourcecode-Dokumentation (Doxygen)
- [x] Anbindung an Travis CI

`https://travis-ci.org/algdat/grp07-algdatII`
- [x] Projekt übersetzen
- [x] Unittests ausführen
- [ ] evtl. Website für das Projekt bauen

## <a name="getting-started"></a>Getting started
Jede Algorithmus-Klasse (*.cpp, *.h) nimmt im Konstruktor als Parameter einen Text und ein Pattern, nach dem gesucht
werden soll. Mit der öffentlichen run() Methode wird er ausgeführt und alle gefundenen Indices im Text als Vector<int>
zurückgegeben.

Ein Sample ist eingefügt (TextSearch.cpp). Er liest eine Textdatei über die Kommandozeile ein und erstellt eine HTML-
Datei im Root mit gefundenen (markierten) Wörtern des Textes.

Um das Projekt zu builden, kann im root per cmake der Prozess gestartet werden.

```
mkdir build
cd build
cmake .. && make && make test 
```

## <a name="resources"></a>Resources
http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/022_c_algorithmen_006.htm  
http://algs4.cs.princeton.edu/lectures/53SubstringSearch.pdf  
http://stackoverflow.com/questions/30548170/dfa-construction-in-knuth-morris-pratt-algorithm?rq=1  
http://stackoverflow.com/questions/4263200/does-kmp-algorithm-peforms-less-comparisons-than-the-simplified-boyer-moore-algo?rq=1

## <a name="license"></a>License
```
Copyright 2016 @ Hochschule München
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```
