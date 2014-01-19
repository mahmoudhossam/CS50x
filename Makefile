dirs = pset1

clean:
	$(foreach dir, $(dirs), $(MAKE) -C $(dir) clean;)

