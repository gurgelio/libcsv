#ifndef FILTER_CONDITIONS_H
#define FILTER_CONDITIONS_H

#include "csv.h"
#include "array.h"

/**
 * Applies an array of filters to the csv
 *
 * @param csv The csv to be filtered
 * @param rowFilterDefinitions The Array of Condition to apply
 *
 * @returns void
 */
void filterConditions(Csv *csv, Array *rowFilterDefinitions);

#endif