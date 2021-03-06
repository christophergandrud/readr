#ifndef FASTREAD_COLLECTORLOGICAL_H_
#define FASTREAD_COLLECTORLOGICAL_H_

#include <cstring>
#include <Rcpp.h>
#include "Collector.h"

class CollectorLogical : public Collector {
public:
  CollectorLogical(): Collector(LogicalVector()) {
  }

  void setValue(int i, const Token& t) {
    LOGICAL(column_)[i] = parse(t);
  }

  int parse(const Token& t) {

    switch(t.type()) {
    case TOKEN_STRING: {
      boost::container::string buffer;
      SourceIterators string = t.getString(&buffer);
      int size = string.second - string.first;
      return (size == 1 && *string.first == 'T') ||
        (size == 4 && strncmp(string.first, "TRUE", 4));
    };
    case TOKEN_MISSING:
    case TOKEN_EMPTY:
      return NA_LOGICAL;
      break;
    case TOKEN_EOF:
      Rcpp::stop("Invalid token");
    }

    return false;
  }

  static bool canParse(std::string x) {
    return x == "T" || x == "F" || x == "TRUE" || x == "FALSE";
  }

};

#endif
