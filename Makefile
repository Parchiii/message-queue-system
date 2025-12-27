dependency:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graphimagefile.png
prepare:
	rm -rf build
	mkdir build
