# Sieve Of Eratosthenes
A simple C++ implementation of the sieve of eratosthenes.
## Argument usage
If you would like to run with arguments the option is available, just follow this convention:<br />
`./main [limit] [mode (0/1/2)]`<br />
Available modes are:
<ol start="0">
  <li>No output</li>
  <li>Printed output</li>
  <li>File output (primes.txt)</li>
</ol><br />
WARNING: Outputting large numbers of primes to a file may have catastrophic consequences, during development I outputted primes under 1 trillion to a file and ended up with an 8GB file and a locked file system before I could stop the program.
