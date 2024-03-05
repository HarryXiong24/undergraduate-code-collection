type PickByType<T, U> = {
    [P in keyof T as T[P] extends U ? P : never]: T[P]
}

type OmitByType<T, U> = Omit<T, keyof PickByType<T, U>>