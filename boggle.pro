QT += core gui
QT += widgets
CONFIG += debug 
HEADERS += board.h\
          display.h \
          game.h \
          trie.h\
          trie_node.h\
          die.h

SOURCES += board.cpp\
         game.cpp \
         trie.cpp\
         die.cpp\
         trie_node.cpp\
         main.cpp
DESTDIR  = build