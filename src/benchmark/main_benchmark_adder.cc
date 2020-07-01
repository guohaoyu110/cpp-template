/**
 * Demo for using Benchmarking using Google's benchmark platform:
 * https://github.com/google/benchmark
 */
<<<<<<< Updated upstream
#include "benchmark/benchmark.h"

#include <iostream>
#include <string>
// benchmark::DoNotOptimize(sum++);
// benchmark::ClobberMemory();

/**
 * Adds value n times and returns the result
 */
unsigned long AddByValue(unsigned long n, unsigned long value) {
  unsigned long sum = 0;
  for (unsigned long i = 0; i < n; i++) {
    sum += value;
  }
  return sum;
}

/**
 * A Benchmark for AddByValue
 */
static void BM_AddByValue(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    AddByValue(state.range(0), state.range(1));
  }
}

/**
 * Increments n times and returns the value
 */
unsigned long Increment(unsigned long n) {
  unsigned long sum = 0;
  for (unsigned long i = 0; i < n; i++) {
    benchmark::DoNotOptimize(sum++);
    benchmark::ClobberMemory();
  }
  return sum;
}
/**
 * A Benchmark for Increment
 */
static void BM_Increment(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    Increment(state.range(0));
  }
}

// Register the function as a benchmark
BENCHMARK(BM_Increment)->RangeMultiplier(2)->Range(1 << 8, 1 << 10);
// =======
// #include <benchmark/benchmark.h>

// #include <chrono>
// #include <string>

// void SomeFunction(size_t size) {
//   std::string s1(size, '-');
//   std::string s2(size, '-');
//   benchmark::DoNotOptimize(s1.compare(s2));
// }

// static void BM_SomeFunction(benchmark::State& state) {
//   // Perform setup here
//   for (auto _ : state) {
//     // This code gets timed
//     SomeFunction(state.range(0)); 
//     SomeFunction(10000);
//   }
// }

// unsigned long Increment(unsigned long n){
//     unsigned long sum = 0;
//     for (unsigned long i = 0; i < n; i++){
//         sum++;
//     }
//     return sum;
// }
// // a benchmark for Increment

// static void BM_Increment(benchmark::State& state){
//     //Perform setup here
//     for (auto _: state){
//         // This code get timed
//         Increment(state.range(0));
//     }
// }


// // Register the function as a benchmark
// BENCHMARK(BM_SomeFunction)->Arg(100000)->Arg(200000)->Arg(400000);
// // gives you an easy way to change the parameters and see the result
// BENCHMARK(BM_SomeFunction)->RangeMultiplier(2)->Range(1 << 10, 1 << 20);
// >>>>>>> Stashed changes

// Run the benchmark
BENCHMARK_MAIN();