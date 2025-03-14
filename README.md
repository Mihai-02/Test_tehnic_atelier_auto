# Atelier auto - Cerinta Proiect

Se va realiza o aplicație pentru gestionarea unui atelier auto. Utilizatorul va avea la dispoziție un meniu
afișat în consolă, prin intermediul căruia se vor realiza operațiile legate de personalul atelierului și de
mașini, astfel:

## I. Angajați

Există 3 tipuri de angajați: Director, Mecanic și Asistent. Toți angajații au în comun câmpurile ID, Nume,
Prenume, Data Nașterii, Data Angajării și Coeficient salariat.

Se vor implementa următoarele funcționalități:
- Afișare angajați
- Adăugare angajat
- Ștergere angajat
- Editare angajat
- Calcularea salariului unui angajat

### Observații:
- Id-ul trebuie să se incrementeze automat pentru fiecare angajat adăugat.
- Coeficientul salarial nu se setează de la tastatură. (Directorul are coeficientul 2, angajatul 1.5 și asistentul 1).
- Numele și prenumele nu trebuie să fie nule și nu trebuie să depășească 30 de caractere fiecare.
- Angajatul trebuie să aibă peste 18 ani, împliniți inclusiv în ziua angajării.
- Data angajării nu poate fi o dată din viitor.
- Ștergerea, editarea și calcularea salariului unui angajat se fac în baza ID-ului acestuia, introdus de la tastatură.
  Dacă ID-ul nu corespunde niciunui angajat, se afișează un mesaj corespunzător și se revine la introducerea ID-ului.
- Calculul salariului se face după formula **Ani vechime * Coeficient * 1000 lei**.

## II. Mașini

Există 3 tipuri de mașini: Standard, Autobuz și Camion. Toate mașinile au în comun câmpurile:
- ID
- Numărul de kilometri
- Anul fabricației
- Un indicator dacă este motor Diesel sau nu.

Fiecare tip de mașină are următoarele specificații suplimentare:
- **Mașinile standard** – un câmp Mod de transmisie (Manual/Automat).
- **Autobuzele** – un câmp Număr de locuri.
- **Camioanele** – un câmp Tonaj.

### Calcul poliță de asigurare:
- **Mașini standard:** Vechime * 100 + 500 (dacă Diesel) + 500 (dacă peste 200.000 km).
- **Autobuze:** Vechime * 200 + 1000 (dacă Diesel) + 1000 (dacă peste 200.000 km) + 500 (dacă peste 100.000 km).
- **Camioane:** Vechime * 300 + 700 (dacă peste 800.000 km).

Mod **DISCOUNT**:
- **5% reducere** pentru mașini standard.
- **10% reducere** pentru autobuze.
- **15% reducere** pentru camioane.

## III. Activitatea Atelierului

Într-un atelier pot lucra mai mulți angajați care pot repara diverse tipuri de mașini, cu următoarele restricții:
1. Trebuie să existe cel puțin un angajat pentru ca atelierul să fie deschis.
2. Angajații pot gestiona cel mult:
   - 3 mașini standard
   - 1 autobuz
   - 1 camion
3. Pe măsură ce finalizează reparațiile, pot prelua alte mașini respectând aceste limite.
4. Un nou vehicul poate fi alocat primului angajat disponibil sau poate solicita un anumit angajat.
5. Dacă toți angajații sunt ocupați, vehiculul poate fi pus în așteptare sau proprietarul poate decide să plece.

Se va implementa un meniu în consolă pentru gestionarea cererilor, afișând mesaje corespunzătoare: 
- „Nu mai sunt locuri libere la un anumit angajat”
- „Nu mai sunt locuri libere în atelier” 
- Afișarea cozii de așteptare.

## IV. Raportare (Opțional)

Pentru evaluarea activității atelierului, permiteți afișarea următoarelor rapoarte, selectate dintr-un meniu afișat în consolă:

1. Angajatul cu cea mai mare încărcare în data curentă.
2. Top 3 angajați care au reparat mașini ce însumează valoarea polițelor de asigurare maximă.
3. Top 3 angajați care au reparat cele mai multe autobuze noi (care au o vechime de mai puțin de 5 ani).
4. Numele și prenumele celor mai solicitați angajați (cei pentru care se fac cereri speciale de către deținătorii de vehicule, pentru a fi reparată mașina special de către aceștia).
5. Bacșișul fiecărui angajat, știind că primește 1% din valoarea poliței de asigurare cu DISCOUNT pentru fiecare mașină reparată.

