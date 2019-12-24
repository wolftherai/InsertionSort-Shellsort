# Insertion-Sort-Shellsort (LT)

## Programos naudojimas:
Paleidus programą vartotojas turi galimybę įvesti visus pradinius duomenis ranka (Insert by hand). Šiuo atveju tektų įvesti aibės ilgį bei kiekvieną skaičių atskirai. Antrojo pasirinkimo atveju mes turime galimybę įvesti masyvo dydį ir programos pagalba skaičių aibė bus sugeneruota automašiškai (Generate random data).

Po aibės sukūrimo mums leidžiama pasirinkti vieną iš dviejų rūšiavimo algoritmų: paprastų įterpimų metodas (Insertion sort) arba Šelo algoritmas (ShellSort).

Pasirinkus vieną iš minėtų funkcijų, gausime algoritmo vykdymo laiką micro sekundėmis ir sekundėmis. Paskutinis menių pasirinkimas būtų išrikiuotos (didėjimo tvarka) skaičių aibės atvaizdavimas konsolėje.

## Užduoties atlikimo algoritmas:
### Paprastų įterpimų metodas:
Šiam algoritmui įgyventi sukurta funkcija InsertionSort(), kuriai paduoti du parametrai – masyvas ilgis „size“ ir pats masyvas „numbers“.

Po to imamas vienas elementas iš eilės (for ciklas) ir dedamas į jam tinkamą vietą (while ciklas). Elementai perkeliami į jiems tinkamas vietas perstūmimų pagalba t.y. swap funkcijos dėka.</br>
Algoritmas vykdomas, kol pasiekiamas paskutinis aibės elementas.
### Šelo algoritmas:
Algoritmas pradedamas vykdyti imant fiksuotą aibės ilgį. Imame pusę aibės – ilgį dalijame iš dviejų.

Šelo algoritmas leidžia paprastai apkeisti vienas nuo kito toli esančius elementus – nereikia perstumdinėti po vieną elementą. Po to tarpas tarp lyginamųjų elementų mažėja. Šiuo būdų visiškai ne savo vietose esantys elementai gali atsidurti savo pozicijose labai greitai.

Algoritmas vykdomas, kol aibės tarpas (ilgis dalintas iš 2) cikle yra didesnis už nulį (nemažiau už vienetą).
## Laiko vykdymo sudėtingumas:

Bendras laiko sudėtingumas paprastųjų įterpimų metodo atveju numatomas kaip O(n + f(n)). f(n) – Inversion count, tai indikatorius nurodantus kaip toli (ar kaip arti) masyvas yra iki visiško išrikiavimo.

Laiko vykdymo sudėtingumas Šelo algoritme(tarpas mažinamas dvigubai per kiekvieną iteraciją) geriausiu atveju yra vertinamas kaip 	O(n* logn), o blogiausias kaip O(n* log2n).
Laiko sudėtingumas Šelo algoritme numatomas netoli O(n) ir mažiau už O(n2).

Iš anksto numanome, jog Šelo algoritmas bus efektyvesnis už paprastųjų įterpimų metodą.
## Testavimas:

Testavimui sukurtas specialus, modifikuotas pagrindinės programos kodas.
1.	Testavimo programoje galime įvesti pradinės duomenų aibės diapazoną. Įvedame intervalus nuo – iki (reikalavime nuo 100 iki 100000).
2.	Sukantis ciklui intervalas didės kas 10%, kad ištestuotumėme algoritmo efektyvumą su įvairių dydžių aibėmis. Aibei didėjant, rikiavimo laikas turėtų dydėti.
3.	Taip pat įvedame kiek kartų norėsime pratestuoti kiekvieną aibės dydį t.y. kiekvieną kartą aibė bus užpildyta vis kitais atsitiktiniais skaičiais. Toks patikrinimas mums reikalingas, kadangi aibė gali būti beveik išrūšiuota arba visiškai išskaidyta.
4.	Išvadoms pagrįsti išrinksime kiekvieno aibės dydžio (ir kiek kartų buvo tas dydis sukamas cikle) apdorojimo vykdymo laiką bei žingsnių vidurkius.
5.	Duomenys išvedami rezultatų faile, kurio pavadinimas:
{pirmas rėžis}_{antras rėžis}_t{kiek kartų generuotos skirtingos reikšmės}_table.csv
pvz.: 100_100000_t5_table.csv (skaičiuota nuo 100 iki 100000, kas 5 kartus, imant 10 % padidėjimą) 

## Efektyvumo lentelė

![alt text](https://github.com/CodeForVGTU/InsertionSort-Shellsort/blob/master/table.png)

- test_times – kiek kartų testuota reikšmė (sudaryta vis nauja aibė)
- array_size – masyvo dydis, su kuriuo atliktas eksperimentas
- avg_steps – vidutinis algoritmo žingsnių kiekis. (visų 4 žingsnių suma / 4 )
- avg_time – vidutinis algoritmo vykdymo laikas (visų 4 vykdymo laiko suma / 4)
- max – maksimalus vykdymo laikas
- min – minimalus vykdymo laikas

## Diagramos
![alt text](https://github.com/CodeForVGTU/InsertionSort-Shellsort/blob/master/diagram.png)

Diagramos sukurtos naudojant efektyvumo lentelę.<br/>
Reikšmių ir žingsnių kiekio santykio lentelėse (kairėje pusėje), x ašyje nurodyta, aibės reikšmės dydis t.y. 1 atitinka 100, o 20 – 100000.  Y ašies dešinėje pusėje nurodytas žingsnių kiekis. Diagrama nurodo kiek žingsnių reikia atlikti, kad būtų išrikiuotas atitinkamo ilgio masyvas.

Laiko ir reikšmių dydžių santykių lentelėse, dešinėje Y pusėje, nurodyti laiko tarpai, per kuriuos atitinkamo dydžio masyvas bus išrikiuotas. Atitinkamomis linijomis diagramoje pavaizduotos vidutinės, didžiausios bei mažiausios reikšmės.
 

## Analizė ir išvados:
Pasitelkus efektyvumo lentelę ir pagal ją sudarytus grafikus, matome, kad nuo 12 elemento (masyvo, kurio dydis 20080), Šelo ir paprastųjų įterpimų algoritmų laikas ir žingsnių kiekiai pradeda sparčiai augti. Prieinama išvada, jog kuo didesnę aibę rūšiuojame, tuo daugiau resursų (laiko) mums prireiks.

Mažų aibių rikiavimui Šelo ir paprastųjų įterpimų algoritmai veikia panašu tempu. Tačiau, kuomet aibės imamos didesnės, skirtumai pradeda ryškėti kur kas žymiau.

Norint išrikiuoti 100000 dydžio masyvą su paprastųjų įterpimų algoritmu, užtrunkame apie 350 sekundžių, kuomet Šelo algoritmas susidoroja su užduotumi per 0.5 sekundės. Žingsnių šiuo atveju Šelui prireikia maždaug per 100 kartų mažiau. Šelo algoritmas yra spartesnis už paprastųjų įterpimų algoritmą. 
