OBJ := main.o databaseHTinit.o createDatabase.o hash_function.o process_word_count.o hashTableInsert.o print_hashTable.o hashTableSearch.o save_to_database.o hashTableDestroy.o

main.exe : $(OBJ)
	gcc -o $@ $^

$(OBJ) :

clean :
	rm *.o *.exe
