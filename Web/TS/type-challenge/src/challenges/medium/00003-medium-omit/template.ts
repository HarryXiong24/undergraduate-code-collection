// this test case, K extends keyof T
type MyOmit<T, K extends keyof T> = {
	[P in Exclude<keyof T, K>]: T[P]
}

// real omit, K extends string | number | symbol
type RealOmit<T, K extends string | number | symbol> = {
	[P in Exclude<keyof T, K>]: T[P]
}