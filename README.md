# Necerini_LabProgrammazione

## Descrizione
La shopping list è un'applicazione in C++ che permette agli utenti di creare e gestire una lista della spesa. Gli utenti possono aggiungere gli oggetti da acquistare, segnarli come completati o ancora da acquistare e rimuoverli dalla lista.

## Funzionalità Principali
Aggiunta di oggetti alla lista della spesa con quantità e categoria

Segnalazione degli oggetti come completati o ancora da acquistare

Rimozione di oggetti dalla lista della spesa

Visualizzazione degli oggetti ancora da acquistare

Stampa della lista della spesa e delle informazioni sugli oggetti completati

## Principali componenti

Classe Item: Rappresenta un oggetto nella lista della spesa con attributi come nome, categoria, quantità e stato di acquisto.

Interfaccia Observer: Definisce il comportamento per gli osservatori che monitorano le modifiche nella lista della spesa.

Interfaccia Subject: Definisce il comportamento per gli oggetti soggetti alle osservazioni, consentendo l'attaccamento, il distacco e la notifica degli osservatori.

Classe ShoppingList: Implementa Subject e rappresenta una lista della spesa con oggetti, categorie e osservatori. Ha metodi per aggiungere, rimuovere e acquistare oggetti, nonché per ottenere informazioni sulla lista e stampare oggetti non acquistati.

Classe User: Implementa Observer e rappresenta un utente che gestisce diverse liste della spesa. Ha metodi per aggiungere e rimuovere liste e per ricevere notifiche sugli aggiornamenti delle liste.

E' stato utilizzato il pattern Observer per consentire agli utenti di essere avvisati quando vengono apportate modifiche alle liste della spesa.






