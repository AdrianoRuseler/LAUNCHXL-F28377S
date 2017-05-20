
This example demonstrates delay capture using the post-processing block.

Two asynchronous ADC triggers are setup:
  - ePWM1, with period 2048, triggering SOC0 to convert on pin A0
  - ePWM1, with period 9999, triggering SOC1 to convert on pin A1

Each conversion generates an ISR at the end of the conversion.  In the
 ISR for SOC0, a conversion counter is incremented and the PPB is checked
 to determine if the sample was delayed.

 After the program runs, the memory will contain:
 - \b conversion \b: the sequence of conversions using SOC0 that were delayed
 - \b delay \b: the corresponding delay of each of the delayed conversions
