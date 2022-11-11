<h1 align="center"> Tugas Besar Alstrukdat <h4 align="center"> Kelompok 10 <h4> <h1>

## Deskripsi 
<div align="center">
<img align="center" src="https://user-images.githubusercontent.com/110550218/199711955-354632d1-cb0c-449f-8f3a-461be3d38099.png">
</div>

<p align="justify"> BNMO adalah sistem <i>game console</i> berisi permainan-permainan seru di dalamnya. BNMO juga memiliki beberapa fitur yang dapat merakayasa daftar game yang disediakan oleh BNMO. Namun, karena alasan teknis, tidak semua <i>game</i> di dalam BNMO tidak dapat dimainkan. Sistem BNMO ini diimplementasikan dalam bentuk <i>Command Line Interface</i> menggunakan bahasa C. Dalam menjalankan BNMO, sistem memanfaatkan struktur data array, mesin karakter, mesin kata, queue, dan map untuk menjalankan program-program menu di dalam BNMO. <p>

## Anggota Kelompok 10
  >Attariq Muhammad Azhar (18221043)
  
  >Mochamad Syahrial A (18221055)
  
  >Iskandar Muda Rizky Parlambang (18221109)
  
  > Devina Ar'raudah (18221113)
  
  > Ariffudin Achmad Subagja (18221127)

## Alur Program
<p align="justify"> Alur penggunaan dari BNMO ini dimulai dengan cara menekan tombol START nya. Sebelum memainkan game kita harus melakukan Load Game terhadap file yang pernah kita simpan sebelumnya. Tujuannya adalah agar pencapaian permainan kita sebelumnya dan dapat diteruskan, alias tidak memulai dari nol lagi. Setelah itu, kita bisa memainkan game yang kita inginkan dengan menambahkannya terlebih dahulu dalam semacam playlist dengan fitur Queue Game. Kita hanya bisa memainkan game sesuai urutannya. Namun, jika kita bosan dan sudah terlanjur memasukkannya dalam playlist tadi, kita bisa menggunakan Skip Game untuk segera menuju game yang kita inginkan. Jika kita bingung ingin memilih game apa, cukup gunakan List Game. Namun, jika masih belum menemukan game yang diinginkan, kita bisa memakai fitur Create Game untuk memasukkan game yang kita inginkan. Jika kita bosan dengan game yang ada, kita juga bisa menghapusnya dari BNMO dengan Delete Game. Jangan lupa gunakan fitur Help jika masih bingung dengan cara memakai BNMO dan tekan Quit jika sudah tidak memakainya lagi agar hemat energi. <p>

## How to use BNMO ??
1. Buka command prompt pada folder bin
2. Ketik make main
3. Ketik main
4. BNMO siap dimainkan 

## Game yang dapat dimainkan oleh BNMO
> RNG

> Diner Dash

> Tebak Kata


## Buku Perjalanan Perbaikan BNMO
<p align="justify">
Setelah berhasil memperbaiki BNMO, 5 Orang programmer handal tersebut menuangkan cerita pengalaman mereka di dalam suatu buku sakral. <p>
 
<p align="Center">
  <a href="https://drive.google.com/drive/folders/19nget4JQghYiOb5zmSfVUjlL9DNyzOtn?usp=share_link">Visit Buku Sakral BNMO!!!
  <a>
<p>

## Directory
|   README.MD
|   .DS_Store
|   bnmo_pic.c
|   bnmo_pic.h
|   main.c
|   
+---.vscode
|      settings.json 
|
+---bin
|       Makefile
|       Main.exe
|       
+---data
|       .DS_Store
|       config.txt
|       savefile1.txt
|       savefile2.txt
|       
+---docs
|       Spesifikasi Tugas Besar 1 IF2111 2022_2023.pdf
|       IF2111_Form_Asistensi_TB01_01_10 .docx.pdf
|       IF2111_TB1_01_10.docx.pdf
|
+---game
|       dinnerdash.c
|       dinnerdash.h
|       queuedinnerdash.c
|       queuedinnerdash.h
|       rng.c
|       rng.h
|       tebakkata.c
|       tebakkata.h
|       
\---program
    |   .DS_Store
    |   create_game.c
    |   create_game.h
    |   delete_game.c
    |   delete_game.h
    |   help.c
    |   help.h
    |   list_game.c
    |   list_game.h
    |   load.c
    |   load.h
    |   load_driver.c
    |   playgame.c
    |   playgame.h
    |   queuegame.c
    |   queuegame.h
    |   save.c
    |   save.h
    |   save_driver.c
    |   skipgame.c
    |   skipgame.h
    |   start.c
    |   start.h
    |   start_driver.c
    |   test.c
    |   
    \---ADT
            |   .DS_Store
            |
            \---Map
                    drivermap.c
                    drivermap.exe
                    map.c
                    map.h
            \---arraydin
                    arraydin.c
                    arraydin.h
                    driverarraydin.c
                    driverarraydin.exe
            \---boolean
                    boolean.h
            \---mesinkarkata
                    drivermesinkarkata.c
                    mesinkar.c
                    mesinkar.h
                    mesinkata.c
                    mesinkata.h
            \---queue
                    driverqueue.c
                    driverqueue.exe
                    queue.c
                    queue.h

