% Generated by roxygen2 (4.1.0): do not edit by hand
% Please edit documentation in R/source.R
\name{new_source}
\alias{new_source}
\title{Create a source object.}
\usage{
new_source(path, text, skip = 0)
}
\arguments{
\item{path}{Either a path to a file, or a connection. Reading directly
from a file is most efficient.}

\item{text}{A character or raw vector. If a character vector, only the
first element is used.}

\item{skip}{Number of lines to skip before reading data.}
}
\description{
Create a source object.
}
\keyword{internal}

