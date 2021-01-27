DEPS = main.c czy_szach.c listaruchowgonca.c listaruchowhetmana.c listaruchowkrola.c listaruchowpionek.c listaruchowskoczka.c listaruchowwiezy.c negamax.c

szachy:$(DEPS)
	gcc $(DEPS) -Wall  -o $@ 

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f szachy
	rm -f *.o
