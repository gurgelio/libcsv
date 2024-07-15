#ifndef FILTER_SELECTIONS_H
#define FILTER_SELECTIONS_H

#include "csv.h"

/**
 * Applies an array of selections to the csv
 *
 * @param csv The csv to be filtered
 * @param rowFilterDefinitions The Array of headers strings to select
 *
 * @returns void
 */
void filterSelections(Csv *csv, Array *selections);

#endif