

CXX = g++ -g
DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
EXE = wumpus

SRC_DIR = .
SRC = $(shell find $(SRC_DIR) -regex ".*\.cpp")

OBJ_DIR = .obj
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

DEP_DIR = .deps
DEP = $(patsubst $(SRC_DIR)/%.cpp,$(DEP_DIR)/%.d,$(SRC))

$(EXE): $(OBJ)
	$(CXX) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_DIR)/%.d $(OBJ_DIR)/%.o.sentinel $(DEP_DIR)/%.d.sentinel
	$(CXX) $(DEP_FLAGS) -I . -c -o $@ $<

$(OBJ_DIR)/%.sentinel:
	@mkdir -p ${@D}
	@touch $@

$(DEP_DIR)/%.sentinel:
	@mkdir -p ${@D}
	@touch $@

$(DEP):

include $(wildcard $(DEP))

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR) $(EXE)

.PHONY: clean
