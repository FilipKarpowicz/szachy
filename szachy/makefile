DEPS = wypisanie.c czy_szach.c listaruchowgonca.c listaruchowhetmana.c listaruchowkrola.c listaruchowpionek.c listaruchowskoczka.c listaruchowwiezy.c negamax.c

wypisanie:$(DEPS)
	gcc $(DEPS) -Wall --pedantic -o $@ 

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f wypisanie
	rm -f *.o
