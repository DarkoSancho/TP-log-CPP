# 📊 Projet d'Analyse de Logs Web

Ce projet vise à analyser les logs de visites de sites web afin de générer un graphe des connexions et d'extraire des statistiques pertinentes.

## 👥 Équipe de développement

Projet réalisé par :
- **Maxence Heurtault**
- **Jade Guedira**
- **Timothée Tavernier**
- **Tom Sanchez**

---

## 🎯 Objectif

L'objectif principal est de **créer un graphe des visites de sites en fonction des logs** et de permettre plusieurs fonctionnalités avancées d'analyse :

✅ Tri des logs selon différents critères :
   - Type de fichier recherché
   - Heure de visite
   - Mots-clés de recherche

✅ Extraction des **10 sites les plus visités**

✅ Génération d'un fichier `.dot` permettant de visualiser le graphe des connexions entre sites

---

## ⚙️ Installation et Exécution

### 📌 Prérequis
- **Système Unix/Linux** (recommandé)
- **Makefile** pour la compilation automatique

### 📥 Compilation

1. **Cloner le dépôt du projet** :
   ```bash
   git clone https://github.com/votre-repo/projet-logs.git
   cd projet-logs
   ```
2. **Compiler le projet** :
   ```bash
   make
   ```



## 📜 Fonctionnalités

### 🔎 Filtres disponibles
- **Tri par type de fichier** : possibilité de ne garder que certains types de fichiers (.html, .png, etc.)
- **Filtrage par heure** : restreindre l'analyse à une plage horaire spécifique
- **Recherche par mots-clés** : extraire uniquement les logs contenant certains termes

### 📊 Statistiques
- Affichage des **10 sites les plus visités**

### 📌 Génération d'un graphe
- **Exportation au format `.dot`** pour visualiser les connexions entre les sites
- Visualisation possible avec **Graphviz** :
  ```bash
  dot -Tpng graphe.dot -o graphe.png
  ```

---

## 🛠️ Tests et Validation

### 📄 Fichiers de test disponibles
Le projet inclut plusieurs fichiers de test permettant de valider son bon fonctionnement.

Pour exécuter les tests :
Aller dans le fichier test puis
```bash
make test
```

---

## 🔥 Contributeurs

📌 **Développé par** : Maxence Heurtault, Jade Guedira, Timothée Tavernier, Tom Sanchez
