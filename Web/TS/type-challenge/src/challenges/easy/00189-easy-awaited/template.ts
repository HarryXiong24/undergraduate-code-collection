type PromiseAny = Promise<any>;
type MyAwaited<T extends PromiseAny> = T extends Promise<infer R> ? R extends PromiseAny ? MyAwaited<R> : R : never;
