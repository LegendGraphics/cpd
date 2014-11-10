
set(3RDPARTY_DIR	${CMAKE_CURRENT_SOURCE_DIR}/cpd/3rdparty)

set(FIGTREE_DIR		${3RDPARTY_DIR}/figtree)
set(FIGTREE_INCLUDE_DIR		${FIGTREE_DIR}/include)
set(FIGTREE_LIBRARY_DIR		${FIGTREE_DIR}/lib)
set(FIGTREE_LIBRARY		optimized ${FIGTREE_LIBRARY_DIR}/figtree_release.lib  
						debug ${FIGTREE_LIBRARY_DIR}/figtree_debug.lib)