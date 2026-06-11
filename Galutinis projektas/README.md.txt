# PC Komponentų Katalogas

## Projekto tikslas

Sukurti C++ konsolinę programą, skirtą PC komponentų katalogo valdymui. Programa leidžia saugoti, peržiūrėti ir redaguoti informaciją apie įvairius kompiuterio komponentus bei išsaugoti duomenis tekstiniame faile.

## Pasirinktos temos aprašymas

Projekto tema – PC komponentų katalogas. Kiekvienas komponentas turi savo ID, gamintoją, modelį, tipą ir kainą. Vartotojas gali pridėti naujus komponentus, redaguoti esamus, juos pašalinti bei atlikti paiešką ir rikiavimą.

## Programos funkcionalumas

Programa suteikia galimybę:

* Peržiūrėti visus komponentus.
* Pridėti naują komponentą.
* Redaguoti esamą komponentą pagal ID.
* Pašalinti komponentą pagal ID.
* Ieškoti komponentų pagal gamintoją.
* Surikiuoti komponentus pagal kainą.
* Išsaugoti pakeitimus tekstiniame faile prieš uždarant programą.

## Naudojami failai

### main.cpp

Pagrindinis programos failas, kuriame realizuotas visas programos funkcionalumas.

### components.txt

Tekstinis failas, kuriame saugomi visi komponentų duomenys.

Duomenų formatas:

```
ID;Gamintojas;Modelis;Tipas;Kaina
```

Pavyzdys:

```
1;AMD;Ryzen7_9800X3D;CPU;549
2;Intel;i7-14700K;CPU;429
3;NVIDIA;RTX5070;GPU;699
```

## Programos paleidimas

1. Atidaryti projektą CLion arba kitoje C++ kūrimo aplinkoje.
2. Įsitikinti, kad failas `components.txt` yra tame pačiame kataloge kaip vykdomasis failas.
3. Sukompiliuoti ir paleisti programą.
4. Naudotis meniu pasirinkimais.

## Papildomos funkcijos

* Komponentų paieška pagal gamintoją.
* Komponentų rikiavimas pagal kainą (Bubble Sort algoritmu).

## Naudotos C++ programavimo priemonės

* `struct`
* `vector`
* Funkcijos
* `if` / `else`
* `switch`
* `for` ir `do-while` ciklai
* Darbas su tekstiniais failais (`ifstream`, `ofstream`)
* `stringstream`
