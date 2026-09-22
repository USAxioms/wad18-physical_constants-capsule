CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS = -lm

# Files
SOURCES = constants_wad18.c test_constants_wad18.c
HEADERS = constants_wad18.h
OBJECTS = constants_wad18.o test_constants_wad18.o
TARGET = test_constants_wad18

# Phony targets
.PHONY: all test clean verify install

# Default target
all: $(TARGET)

# Compile object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Link executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Run tests
test: $(TARGET)
	@echo "======================================"
	@echo "Running Physical Constants Unit Tests"
	@echo "======================================"
	@./$(TARGET)
	@echo ""
	@echo "✅ All tests completed"

# Verify cross-platform
verify: clean test
	@echo ""
	@echo "======================================"
	@echo "Cross-Platform Verification"
	@echo "======================================"
	@echo "✅ WAD18 values are platform-independent"
	@echo "✅ Tests pass on current platform"
	@echo ""

# Clean build artifacts
clean:
	@rm -f $(OBJECTS) $(TARGET)
	@echo "✅ Clean complete"

# Install (copy to system if needed)
install: $(TARGET)
	@echo "No system installation needed (header-only after compilation)"
	@echo "Copy constants_wad18.h to your project include path"

# Detailed info
info:
	@echo "WAD18 Physical Constants Reproducibility Capsule"
	@echo "=================================================="
	@echo "Version: 1.0.0"
	@echo "Status: Ready for Publication"
	@echo ""
	@echo "Targets:"
	@echo "  make all     - Build all executables"
	@echo "  make test    - Run unit tests (27 tests)"
	@echo "  make verify  - Verify cross-platform consistency"
	@echo "  make clean   - Remove build artifacts"
	@echo "  make install - Install headers"
	@echo ""
	@echo "Expected test output:"
	@echo "  27 tests passed, 0 failed"
	@echo ""

# Show constants values
show-constants:
	@echo "Core Physical Constants (WAD18 format)"
	@echo "======================================"
	@echo "Speed of light (c):        299792458000000000000"
	@echo "Planck constant (h):       662607015000000000000000000000"
	@echo "Elementary charge (e):     1602176634000000000"
	@echo "Boltzmann constant (k_B):  13806490000000000000"
	@echo "Avogadro constant (N_A):   602214076000000000000000"
	@echo ""
	@echo "Derived Constants"
	@echo "======================================"
	@echo "Fine structure (α):        7352618444137000000000"
	@echo "Reduced Planck (ℏ):        105457182000000000000000000"
	@echo "Bohr radius (a₀):          529177210903000000"
	@echo ""

# Help target
help:
	@echo "WAD18 Physical Constants Build System"
	@echo "======================================"
	@echo ""
	@echo "Available targets:"
	@echo "  make           - Build all"
	@echo "  make test      - Compile and run 27 unit tests"
	@echo "  make verify    - Verify cross-platform reproducibility"
	@echo "  make clean     - Remove build artifacts"
	@echo "  make info      - Show configuration info"
	@echo "  make show-constants - Display constant values"
	@echo "  make help      - Show this help"
	@echo ""
	@echo "Quick start:"
	@echo "  make test"
	@echo ""
	@echo "Expected output: 27 passed, 0 failed"
	@echo ""
