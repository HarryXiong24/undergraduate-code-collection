type MyParameters<Fn extends (...args: any) => any> = Fn extends (...args: infer P) => any ? P : never;
type MyReturnType<Fn extends (...args: any) => any> = Fn extends (...args: any) => infer R ? R : any;

type AppendArgument<Fn extends (...args: any) => unknown, A> = (...args: [...MyParameters<Fn>, A]) => MyReturnType<Fn>;
