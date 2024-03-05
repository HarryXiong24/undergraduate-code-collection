/**
 * Enum
 */

// Javascript
const MAX_NUM = 6;
const MAX_STUDENT_PER_CLASS = 10;
const MONDAY = 0;
const TUESDAY = 1;
const DAYS_ENUM = Object.freeze({
  MONDAY: 0,
  TUESDAY: 1,
  WEDNESDAY: 2,
});
const dayOfToday = DAYS_ENUM.MONDAY;

// TypeScript
// if not specifies value, it starts from 0
// BAD
enum Days {
  Monday = 1,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday,
}
console.log(Days.Tuesday);
const day = Days.Saturday;

// GOOD
type DaysOfWeek = 'Monday' | 'Tuesday' | 'Wednesday';
let dayOfWeek: DaysOfWeek = 'Monday';
// dayOfWeek = 'youngjun'; // error
