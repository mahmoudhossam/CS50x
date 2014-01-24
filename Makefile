dirs = pset1 pset2

clean:
	$(foreach dir, $(dirs), $(MAKE) -C $(dir) clean;)

