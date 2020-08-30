.PHONY: clean All

All:
	@echo "----------Building project:[ Overloading-Operators-2.0 - Debug ]----------"
	@"$(MAKE)" -f  "Overloading-Operators-2.0.mk"
clean:
	@echo "----------Cleaning project:[ Overloading-Operators-2.0 - Debug ]----------"
	@"$(MAKE)" -f  "Overloading-Operators-2.0.mk" clean
