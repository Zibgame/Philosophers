# 🧠 Philosophers (42)

Projet du cursus 42 basé sur le célèbre Dining Philosophers Problem. Simulation multi-threads où chaque philosophe pense, mange et dort 🍽️😴. La difficulté est de gérer les ressources partagées via mutex sans deadlock ni starvation 🔒. Le but est d’assurer une synchronisation propre, précise et performante ⚡ et de comprendre les bases de la concurrence, du timing et de la gestion des threads.

## 🚀 Fonctionnalités
- Simulation en temps réel  
- Gestion des accès aux fourchettes via mutex  
- Aucun blocage, aucun philosophe affamé  
- Messages synchronisés et horodatés  

## 🛠️ Compilation
```bash
make
./philo <nb_philo> <time_to_die> <time_to_eat> <time_to_sleep> [meals]

```

## 📌 Objectifs pédagogiques
Comprendre la concurrence, éviter les race conditions, maîtriser les threads et construire une architecture stable et robuste.

## 🧩 Exemple
./philo 5 800 200 200

bash
Copier le code

## 📄 Statut
Projet réalisé dans le cadre du cursus École 42 Le Havre.
