hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/DugumAgac.o -c ./src/DugumAgac.cpp
	g++ -I ./include/ -o ./lib/Hata.o -c ./src/Hata.cpp
	g++ -I ./include/ -o ./lib/BagilListe.o -c ./src/BagilListe.cpp

	g++ -I ./include/ -o ./lib/BinarySearchTree.o -c ./src/BinarySearchTree.cpp	
	g++ -I ./include/ -o ./lib/ListeGezici.o -c ./src/ListeGezici.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Hata.o ./lib/BagilListe.o  ./lib/BinarySearchTree.o ./lib/DugumAgac.o   ./lib/ListeGezici.o ./src/test.cpp
	
calistir:
	./bin/test