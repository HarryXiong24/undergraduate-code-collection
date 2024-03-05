type ComputedType<C> = {
	[K in keyof C]: C[K] extends () => infer R ? R : C[K]
}

// type ComputedType<C> = C extends Record<string, () => infer ReturnType> ? Record<string, ReturnType> : C;

declare function SimpleVue<D, C, M>(options: {
	data: (this: {}) => D,
	computed: C & ThisType<D>,
	methods: M & ThisType<D & M & ComputedType<C>>
}): any
