#compilations_option

game: 
	$(CC) -g Moduly/main.c Moduly/modes.c Moduly/save_image.c Moduly/manage_generations.c Moduly/create_new.c Moduly/help_create.c Moduly/neighbor.c Moduly/personal.c -Wall -pedantic -o game
	
changeIN: 
	$(CC) -g  Moduly/main.c Moduly/modes.c Moduly/save_image.c Moduly/manage_generations.c Moduly/create_new.c Moduly/help_create.c Moduly/neighbor.c Moduly/personal.c -Wall -pedantic -o change -DIN='"./Generacje_Wyjsciowe/"'

change_OUT:
	$(CC) -g Moduly/main.c Moduly/modes.c Moduly/save_image.c Moduly/manage_generations.c Moduly/create_new.c Moduly/help_create.c Moduly/neighbor.c Moduly/personal.c -Wall -pedantic -o change -DOUT='"./Generacje_Wejsciowe/"'

change_SIZE:
	$(CC) -g Moduly/main.c Moduly/modes.c Moduly/save_image.c Moduly/manage_generations.c Moduly/create_new.c Moduly/help_create.c Moduly/neighbor.c Moduly/personal.c -Wall -pedantic -o change -DSIZE=10

change_HOW_FAST:
	$(CC) -g Moduly/main.c Moduly/modes.c Moduly/save_image.c Moduly/manage_generations.c Moduly/create_new.c Moduly/help_create.c Moduly/neighbor.c Moduly/personal.c -Wall -pedantic -o change -DHOW_FAST=100000



#run_options

run_sbs: change_IN
	./change --in blabla.txt --out bla.txt  -n 20 --how Ps -m sbs 
	rm -f change
run_fast: game
	./game --in starship.txt --out wunik.txt -s f5 -n 100 --how Ms -m sbs
	rm -f game
no_save: game
	./game --in smile.txt --out sofa.txt -n 300 --how Ps -m sbs
	rm -f game

after_change: change_IN
	./change --in blabla.txt --out newblabla.txt -n 40 --how Ms -m sbs
	rm -f change


#remove_files

remove_out:
	rm Generacje_Wyjsciowe/*.txt 
remove_image:
	rm Obrazy/generation*


#test_calls

test2: game
	./game --in blad_kolumn.txt --out wynik.txt -n 30 --how Ns -m sbs
	rm -f game
test3.1: game
	./game --in blad_tablicy.txt --out wynik.txt -n 30 --how Ms -m sbs
	rm -f game
test3.2: game
	./game --in blad_tablica_roz.txt --out wynik.txt -n 30 --how Ms -m sbs
	rm -f game
test4.1: game	
	./game --in starship.txt --out wynik.txt -n 30 --how Ms -m sbs -pifpaf martwy_pan
	rm -f game
test4.2: game
	./game --in starship.txt --out wynik.txt -n 30 --how Ms 
	rm -f game
test4.3: game
	./game --in starship --out wynik.txt -n 30 --how Ms -m sbs 
	rm -f game
test4.4: game
	./game --in starship.txt --out wynik.txt -n -5 --how Ms -m sbs
	rm -f game
test4.5: game
	./game --in starship.txt --out wynik.txt -n 30 --how -m sbs 
	rm -f game
test4.6: game
	./game --in starship.txt --out wynik.txt -n 30 --how Ms -m Maryla_Rodowicz 
	rm -f game






