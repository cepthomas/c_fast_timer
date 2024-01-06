#ifndef TIME_ANALYZER_H
#define TIME_ANALYZER_H


#include <windows.h>

/// Number of data points to grab for statistics. TODO make user selectable.
#define NUM_SAMPLES 100

/// Analysis results in msec.
typedef struct time_results
{
    int num_samples;
    double mean;
    double min;
    double max;
    double sd;
} time_results_t;


/// Initialize.
/// @return valid
bool timeanalyzer_Init(void);

/// Resets everythin.
/// @return valid
void timeanalyzer_Reset(void);

/// Start or stop the analysis.
/// @param[in] on T/F
/// @return running
bool timeanalyzer_Run(bool on);

/// Start timing capture.
void timeanalyzer_Arm(void);

/// Capture a time value.
/// @param[in] name desc
/// @return pointer to results if completed else NULL.
time_results_t* timeanalyzer_Grab(void);

#endif // TIME_ANALYZER_H
