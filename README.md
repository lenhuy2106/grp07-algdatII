[![Build Status](https://travis-ci.org/algdat/grp07-algdatII.svg?branch=master)](https://travis-ci.org/algdat/grp07-algdatII)

grp07-algdatII

# Text-Suche in dynamischen Texten

Implementierung und Vergleich von drei Algorithmen auf Laufzeit.

## Table of Contents

* [Team Members](#team-members)
* [Introduction](#intro)
* [Getting started](#getting-started)

## <a name="team-members"></a>Team Members
* "Maximilian Keil" (Sweetboi) 
* "Andi Buchmann" (Bookman)
* "Nhu Huy Le" <nle@hm.edu> (Boss)
* Long Mathias Yan (China)

## <a name="intro"></a>Introduction
Im Rahmen der Vorlesung _Algorithmen und Datenstrukturen 2_ im SS 16 an der Hochschule München entwickeln
und vergleichen wir drei Algorithmen für die Textsuche in dynamischen (veränderlichen) Texten:

* (Unterbrechender) Naiver Algorithmus
* Knuth-Morris-Pratt Algorithmus
* Boyer-Moore-Horspool Algorithmus


## <a name="getting-started"></a>Getting started
Jede Algorithmus-Klasse (*.cpp, *.h) nimmt im Konstruktor als Parameter einen Text und ein Pattern, nach dem gesucht
werden soll. Mit der öffentlichen run() Methode wird er ausgeführt und alle gefundenen Indices im Text als Vector<int>
zurückgegeben.

Ein Sample ist eingefügt (TextSearch.cpp). Er liest eine Textdatei über die Kommandozeile ein und erstellt eine HTML-
Datei im Root mit gefundenen (markierten) Wörtern des Textes.

Um das Projekt zu builden, kann im root per cmake der Prozess gestartet werden.

<pre><code>mkdir build
cd build
cmake .. && make && make test 
</code></pre>
