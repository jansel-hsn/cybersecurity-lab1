# 🔐 Киберсигурност - Лабораторно упражнение 1

## 📚 Описание

Проектът съдържа основни задачи по киберсигурност, реализирани на езика C.  
Изпълнен е като част от университетски курс по киберсигурност.

## 🧪 Покрити теми

* Цезаров шифър (Brute-force атака)
* Честотен анализ
* Виженеров шифър
* Метод на Касиски
* Анализ на сигурността на пароли

## 💻 Език

C

## ⚙️ Компилация

```bash
gcc caesar_brute_force.c -o caesar
gcc frequency_analysis_caesar.c -o frequency
gcc vigenere.c -o vigenere
gcc vigenere_file_io.c -o vigenere_file
gcc kasiski_helper.c -o kasiski
gcc password_strength_analyzer.c -o password
```

## ▶️ Стартиране

```bash
./caesar
./frequency
./vigenere
./vigenere_file
./kasiski
./password
```

## 📂 Структура на проекта

* caesar_brute_force.c – brute-force атака върху Цезаров шифър  
* frequency_analysis_caesar.c – честотен анализ на буквите  
* vigenere.c – имплементация на Виженеров шифър  
* vigenere_file_io.c – криптиране/декриптиране с файлов вход/изход  
* kasiski_helper.c – откриване на повтарящи се триграми (метод на Касиски)  
* password_strength_analyzer.c – оценка на сигурността на парола  

## 👩‍💻 Автор

Джансел Хасан Мустафа  
Студент по софтуерно инженерство  
Университет „Проф. д-р Асен Златаров“ – Бургас
