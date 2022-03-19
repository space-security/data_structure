# first_make
# $^ 依赖 不重复
# $@ 目标
# @ 不显示命令执行内容
# - 即便失败依然执行下面的程序
TARGET=first_make
LIBS=-lpthread

$(TARGET):first_make.cpp xdata.cpp
	@# -@rm test
	@echo "begin bulid $(TARGET)"
	@$(CXX) $^ -o $@ $(LIBS)
	@echo "$(TARGET) bulid success!"

clean:
	@$(RM) $(TARGET)
.PHONY: clean