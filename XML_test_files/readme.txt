Dieses Verzeichnis enthält Beispieldateien zum Testen Ihres Programms. 
Schauen Sie sich zuerst den Inhalt der Dateien an, bevor Sie damit testen.

Nach dem Schema "broken?.xml" benannte Dateien enthalten Fehler.
Syntaktisch korrekte XML-Beispiele finden sich in "valid?.xml".

Es handelt sich hier um recht einfache XML-Beispieldateien, Sie können aber 
gerne noch nach komplexeren Beispielen suchen (oder sich diese ausdenken).

Sie können sich ggfs. das Testen mit der folgenden Variablen erleichtern: 

std::vector<std::string> files{
    "stud.xml",
    "broken1.xml", "broken2.xml", "broken3.xml",
    "broken4.xml", "broken5.xml", "broken6.xml",
    "broken7.xml", "broken8.xml", "broken9.xml",
    "valid1.xml", "valid2.xml", "valid3.xml"
};
