<h1 align="center"> Tugas Besar Alstrukdat <h4 align="center"> Kelompok 10 <h4> <h1>

## Deskripsi 
<div align="center">
<img src="https://user-images.githubusercontent.com/110550218/199711955-354632d1-cb0c-449f-8f3a-461be3d38099.png">
</div>

<p align="justify"> BNMO adalah sistem <i>game console</i> berisi permainan-permainan seru di dalamnya. BNMO juga memiliki beberapa fitur yang dapat merakayasa daftar game yang disediakan oleh BNMO. Namun, karena alasan teknis, tidak semua <i>game</i> di dalam BNMO dapat dimainkan. Sistem BNMO ini diimplementasikan dalam bentuk <i>Command Line Interface</i> menggunakan bahasa C. Dalam menjalankan BNMO, sistem memanfaatkan Abstrak Data Type Array, Mesin Karakter, Mesin Kata, Queue, List, Set, Map, Stack, serta Tree untuk menjalankan program-program menu di dalam BNMO. <p>

## Anggota Kelompok 10
  >Attariq Muhammad Azhar (18221043)
  
  >Mochamad Syahrial A (18221055)
  
  >Iskandar Muda Rizky Parlambang (18221109)
  
  > Devina Ar'raudah (18221113)
  
  > Ariffudin Achmad Subagja (18221127)

## Alur Program
<p align="justify"> Alur penggunaan dari BNMO ini dimulai dengan cara menekan tombol START nya. Sebelum memainkan game kita harus melakukan Load Game terhadap file yang pernah kita simpan sebelumnya. Tujuannya adalah agar pencapaian permainan kita sebelumnya dan dapat diteruskan, alias tidak memulai dari nol lagi. Setelah itu, kita bisa memainkan game yang kita inginkan dengan menambahkannya terlebih dahulu dalam semacam playlist dengan fitur Queue Game. Kita hanya bisa memainkan game sesuai urutannya. Namun, jika kita bosan dan sudah terlanjur memasukkannya dalam playlist tadi, kita bisa menggunakan Skip Game untuk segera menuju game yang kita inginkan. Jika kita bingung ingin memilih game apa, cukup gunakan List Game. Namun, jika masih belum menemukan game yang diinginkan, kita bisa memakai fitur Create Game untuk memasukkan game yang kita inginkan. Jika kita bosan dengan game yang ada, kita juga bisa menghapusnya dari BNMO dengan Delete Game. Selanjutnya pada BNMO versi terbaru, terdapat fitur Scoreboad, serta Reset Scoreboard. Hal ini dibuat untuk meningkatkan sifat kompetitif pemain. Selain itu, juga terdapat tambahin fitur berupa History. Fitur tersebut berfungsi untuk mengecek permainan apa saja yang telah dimainkan. Kemudian, dengan BNMO versi terbaru ini pemain juga dapat mereset history dengan menggunakan fitur Reset History. Jangan lupa gunakan fitur Help jika masih bingung dengan cara memakai BNMO dan tekan Quit jika sudah tidak memakainya lagi agar hemat energi. <p>

## How to use BNMO ??
make main Way:
  
    1. Buka command prompt pada folder bin
    2. Ketik make main
    3. Ketik main
    4. BNMO siap dimainkan 

gcc Way:
  
    1. Buka command prompt pada folder bin
    2. Ketik 
  
          "gcc program/ADT/mesinkarkata/mesinkata.c program/ADT/mesinkarkata/mesinkar.c program/ADT/arraydin/arraydin.c program/ADT/queue/queue.c program/load.c    program/start.c program/save.c program/create_game.c program/list_game.c program/delete_game.c program/queuegame.c program/playgame.c program/skipgame.c program/help.c program/ADT/stack/stack.c program/ADT/Map/map.c program/history.c program/scoreboard.c bnmo_pic.c main.c game/dinnerdash.c game/SnakeOnMeteor.c game/towerofhanoi.c game/rng.c game/tebakkata.c game/queuedinnerdash.c game/hangman.c program/ADT/Set/sethangman.c program/ADT/listdp/listdp.c program/ADT/Map/mapchar.c program/ADT/StackHanoi/stackhanoi.c program/ADT/Set/set.c  game/akinator.c program/ADT/Tree/tree.c program/ADT/MesinkarkataAkinator/mesinkarakinator.c program/ADT/MesinkarkataAkinator/mesinkataakinator.c -o main"

    3. Ketik /.main
    4. BNMO siap dimainkan
  
## Game yang dapat dimainkan oleh BNMO
> Akinator (New!)

> Diner Dash

> Hangman (New!)

> RNG

> Snake On Meteor (New!)

> Tebak Kata

> Tower of Hanoi (New!)

## Buku Perjalanan Perbaikan BNMO
<p align="justify">
Setelah berhasil memperbaiki BNMO, 5 Orang programmer handal tersebut menuangkan cerita pengalaman mereka di dalam suatu buku sakral. <p>
 
<p align="Center">
  <a href="https://drive.google.com/drive/folders/19nget4JQghYiOb5zmSfVUjlL9DNyzOtn?usp=share_link">Visit Buku Sakral BNMO!!!
  <a>
<p>

<p align="justify">
Namun, siapa sangka 5 orang programmer itu melanjutkan kisah tersebut. Kisah mereka berlanjut mengenai pengembangan BNMO. 
<p>

<p align="Center">
  <a href="https://drive.google.com/drive/folders/1ZabfZNvtebZrZluKDU_7hIlB22NToe6M?usp=share_link"> Buku Sakral BNMO Vol. 2 !!!
  <a>
<p>

## Directory
📦.vscode
  
    ┗ 📜settings.json

📦bin
  
    ┣ 📜main
    ┗ 📜Makefile

📦data
  
    ┣ 📜.DS_Store
    ┣ 📜backup.txt
    ┣ 📜config.txt
    ┣ 📜haha.txt
    ┣ 📜kamus.txt
    ┣ 📜ngasal.txt
    ┣ 📜savefile1.txt
    ┗ 📜savefile2.txt

📦docs
  
    ┣ 📜IF2111_Form Asistensi TB1_01_10.pdf
    ┣ 📜IF2111_Form Asistensi TB2_01_10.pdf
    ┣ 📜IF2111_TB1_01_10.pdf
    ┣ 📜IF2111_TB2_01_10.pdf
    ┣ 📜Spesifikasi Tugas Besar 1 IF2111 2022_2023.pdf
    ┗ 📜Spesifikasi Tugas Besar 2 IF2111 2022_2023.pdf

📦game
  
    ┣ 📂DataAkinator
    ┃ ┣ 📜akinator.txt
    ┃ ┣ 📜hewan.txt
    ┃ ┗ 📜jawaban.txt
    ┣ 📜akinator.c
    ┣ 📜akinator.h
    ┣ 📜dinnerdash.c
    ┣ 📜dinnerdash.h
    ┣ 📜driverqueuedinnerdash.c
    ┣ 📜Hangman.c
    ┣ 📜Hangman.h
    ┣ 📜queuedinnerdash.c
    ┣ 📜queuedinnerdash.h
    ┣ 📜rng.c
    ┣ 📜rng.h
    ┣ 📜SnakeOnMeteor.c
    ┣ 📜SnakeOnMeteor.h
    ┣ 📜snake_driver.c
    ┣ 📜tebakkata.c
    ┣ 📜tebakkata.h
    ┣ 📜towerofhanoi.c
    ┣ 📜towerofhanoi.h
    ┗ 📜ular

📦program
  
    ┣ 📂ADT
    ┃ ┣ 📂arraydin
    ┃ ┃ ┣ 📜arraydin.c
    ┃ ┃ ┣ 📜arraydin.h
    ┃ ┃ ┣ 📜driverarraydin.c
    ┃ ┃ ┗ 📜driverarraydin.exe
    ┃ ┣ 📂boolean
    ┃ ┃ ┗ 📜boolean.h
    ┃ ┣ 📂listdp
    ┃ ┃ ┣ 📜driverlistdp.c
    ┃ ┃ ┣ 📜driverlistdp.exe
    ┃ ┃ ┣ 📜listdp.c
    ┃ ┃ ┗ 📜listdp.h
    ┃ ┣ 📂listSetMap
    ┃ ┃ ┣ 📜driverlistSetMap.c
    ┃ ┃ ┣ 📜driverlistSetMap.exe
    ┃ ┃ ┣ 📜listSetMap.c
    ┃ ┃ ┗ 📜listSetMap.h
    ┃ ┣ 📂Map
    ┃ ┃ ┣ 📜drivermap.c
    ┃ ┃ ┣ 📜drivermap.exe
    ┃ ┃ ┣ 📜drivermapchar.c
    ┃ ┃ ┣ 📜drivermapchar.exe
    ┃ ┃ ┣ 📜map.c
    ┃ ┃ ┣ 📜map.h
    ┃ ┃ ┣ 📜mapchar.c
    ┃ ┃ ┗ 📜mapchar.h
    ┃ ┣ 📂mesinkarkata
    ┃ ┃ ┣ 📜drivermesinkarkata.c
    ┃ ┃ ┣ 📜drivermesinkarkata.exe
    ┃ ┃ ┣ 📜mesinkar.c
    ┃ ┃ ┣ 📜mesinkar.h
    ┃ ┃ ┣ 📜mesinkata.c
    ┃ ┃ ┗ 📜mesinkata.h
    ┃ ┣ 📂MesinkarkataAkinator
    ┃ ┃ ┣ 📜drivermesinkarkataakinator.c
    ┃ ┃ ┣ 📜drivermesinkarkataakinator.exe
    ┃ ┃ ┣ 📜mesinkarakinator.c
    ┃ ┃ ┣ 📜mesinkarakinator.h
    ┃ ┃ ┣ 📜mesinkataakinator.c
    ┃ ┃ ┗ 📜mesinkataakinator.h
    ┃ ┣ 📂queue
    ┃ ┃ ┣ 📜driverqueue.c
    ┃ ┃ ┣ 📜driverqueue.exe
    ┃ ┃ ┣ 📜queue.c
    ┃ ┃ ┗ 📜queue.h
    ┃ ┣ 📂Set
    ┃ ┃ ┣ 📜driverset.c
    ┃ ┃ ┣ 📜driverset.exe
    ┃ ┃ ┣ 📜set.c
    ┃ ┃ ┣ 📜set.h
    ┃ ┃ ┣ 📜sethangman.c
    ┃ ┃ ┗ 📜sethangman.h
    ┃ ┣ 📂Stack
    ┃ ┃ ┣ 📜driverstack.c
    ┃ ┃ ┣ 📜driverstack.exe
    ┃ ┃ ┣ 📜stack.c
    ┃ ┃ ┗ 📜stack.h
    ┃ ┣ 📂StackHanoi
    ┃ ┃ ┣ 📜driverstackhanoi.c
    ┃ ┃ ┣ 📜driverstackhanoi.exe
    ┃ ┃ ┣ 📜stackhanoi.c
    ┃ ┃ ┗ 📜stackhanoi.h
    ┃ ┣ 📂Tree
    ┃ ┃ ┣ 📜drivertree.c
    ┃ ┃ ┣ 📜drivertree.exe
    ┃ ┃ ┣ 📜tree.c
    ┃ ┃ ┣ 📜tree.h
    ┃ ┃ ┗ 📜tree.txt
    ┃ ┗ 📜.DS_Store
    ┣ 📜.DS_Store
    ┣ 📜create_game.c
    ┣ 📜create_game.h
    ┣ 📜delete_game.c
    ┣ 📜delete_game.h
    ┣ 📜help.c
    ┣ 📜help.h
    ┣ 📜history.c
    ┣ 📜history.h
    ┣ 📜list_game.c
    ┣ 📜list_game.h
    ┣ 📜load.c
    ┣ 📜load.h
    ┣ 📜loadhangman.c
    ┣ 📜load_driver
    ┣ 📜load_driver.c
    ┣ 📜playgame.c
    ┣ 📜playgame.h
    ┣ 📜queuegame.c
    ┣ 📜queuegame.h
    ┣ 📜save.c
    ┣ 📜save.h
    ┣ 📜save_driver.c
    ┣ 📜scoreboard.c
    ┣ 📜scoreboard.h
    ┣ 📜skipgame.c
    ┣ 📜skipgame.h
    ┣ 📜start.c
    ┣ 📜start.h
    ┗ 📜start_driver.c
 
📦bnmo_pic.c
 
📦bnmo_pic.exe
 
📦bnmo_pic.h

📦load_driver

📦main

📦main.c

📦README.md
