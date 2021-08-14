export type IconModel = {
    title: string,
    viewBox: string,
    d: string
}

const icon_code = {
    title: 'code',
    viewBox: '0 0 20 20',
    d: `M6 6a1.003 1.003 0 0 0-1.71-.71l-4 4C.11 9.47 0 9.72 0 10c0 .28.11.53.29.71l4 4a1.003 1.003 0 0 0 1.42-1.42L2.41 10 5.7 6.71c.19-.18.3-.43.3-.71zm6-4c-.46 0-.83.31-.95.73l-4 14c-.02.09-.05.17-.05.27 0 .55.45 1 1 1 .46 0 .83-.31.95-.73l4-14c.02-.09.05-.17.05-.27 0-.55-.45-1-1-1zm7.71 7.29l-4-4a1.003 1.003 0 0 0-1.42 1.42l3.3 3.29-3.29 3.29c-.19.18-.3.43-.3.71a1.003 1.003 0 0 0 1.71.71l4-4c.18-.18.29-.43.29-.71 0-.28-.11-.53-.29-.71z`
}

const icon_minus = {
    title: 'minus',
    viewBox: '0 0 20 20',
    d: `M16 9H4c-.55 0-1 .45-1 1s.45 1 1 1h12c.55 0 1-.45 1-1s-.45-1-1-1z`
}

const icon_plus = {
    title: 'plus',
    viewBox: '0 0 20 20',
    d: `M16 9h-5V4c0-.55-.45-1-1-1s-1 .45-1 1v5H4c-.55 0-1 .45-1 1s.45 1 1 1h5v5c0 .55.45 1 1 1s1-.45 1-1v-5h5c.55 0 1-.45 1-1s-.45-1-1-1z`
}

const icon_eye_off = {
    title: 'eye-off',
    viewBox: '0 0 20 20',
    d: `M20 9.96v-.03-.01-.02-.02a.794.794 0 0 0-.21-.43c-.55-.69-1.19-1.3-1.85-1.87l-3.93 2.62a3.966 3.966 0 0 1-3.96 3.77c-.47 0-.91-.1-1.33-.24l-2.24 1.49c.52.21 1.05.39 1.6.51 1.21.27 2.43.28 3.64.05 1.11-.21 2.17-.64 3.17-1.18 1.56-.84 2.99-2 4.23-3.3.23-.24.46-.49.67-.75a.87.87 0 0 0 .21-.43v-.02-.02-.01-.03V10v-.04zm-.46-5.14c.27-.18.46-.47.46-.82 0-.55-.45-1-1-1-.21 0-.39.08-.54.18l-.01-.02L15 5.46c-.95-.53-1.95-.96-3.01-1.2a9.158 9.158 0 0 0-3.65-.04c-1.11.21-2.17.64-3.17 1.18-1.56.84-2.99 2-4.23 3.3-.23.24-.46.48-.67.75-.27.34-.27.76 0 1.1.64.79 1.39 1.5 2.16 2.15.26.21.52.41.79.61L.44 15.16l.01.02A1 1 0 0 0 0 16c0 .55.45 1 1 1 .21 0 .39-.08.54-.18l.01.02 18-12-.01-.02zm-8.67 3.4c-.25-.12-.53-.2-.83-.2-1.1 0-1.99.89-1.99 1.99 0 .03.02.06.02.09l-1.78 1.19c-.14-.4-.22-.83-.22-1.28 0-2.19 1.78-3.97 3.98-3.97 1.01 0 1.91.38 2.61 1l-1.79 1.18z`
}

const icon_check: IconModel = {
    title: 'check',
    viewBox: `0 0 20 20`,
    d: `M17 4c-.28 0-.53.11-.71.29L7 13.59 3.71 10.3A.965.965 0 0 0 3 10a1.003 1.003 0 0 0-.71 1.71l4 4c.18.18.43.29.71.29s.53-.11.71-.29l10-10A1.003 1.003 0 0 0 17 4z`
}

const icon_close: IconModel = {
    title: 'close',
    viewBox: '0 0 20 20',
    d: `M11.41 10l4.29-4.29c.19-.18.3-.43.3-.71a1.003 1.003 0 0 0-1.71-.71L10 8.59l-4.29-4.3a1.003 1.003 0 0 0-1.42 1.42L8.59 10 4.3 14.29c-.19.18-.3.43-.3.71a1.003 1.003 0 0 0 1.71.71l4.29-4.3 4.29 4.29c.18.19.43.3.71.3a1.003 1.003 0 0 0 .71-1.71L11.41 10z`
}

const icon_warn: IconModel = {
    title: 'warn',
    viewBox: '0 0 20 20',
    d: `M19.86 17.52l.01-.01-9-16-.01.01C10.69 1.21 10.37 1 10 1s-.69.21-.86.52l-.01-.01-9 16 .01.01c-.08.14-.14.3-.14.48 0 .55.45 1 1 1h18c.55 0 1-.45 1-1 0-.18-.06-.34-.14-.48zM11 17H9v-2h2v2zm0-3H9V6h2v8z`
}

const icon_caret_down = {
    title: 'caret-down',
    viewBox: '0 0 20 20',
    d: `M16 7c0-.55-.45-1-1-1H5c-.55 0-1 .45-1 1 0 .24.1.46.24.63l-.01.01 5 6 .01-.01c.19.22.45.37.76.37s.57-.15.76-.37l.01.01 5-6-.01-.01c.14-.17.24-.39.24-.63z`
}

const icon_caret_up = {
    title: 'caret-up',
    viewBox: '0 0 20 20',
    d: `M15.76 12.37l.01-.01-5-6-.01.01C10.57 6.15 10.31 6 10 6s-.57.15-.76.37l-.01-.01-5 6 .01.01c-.14.17-.24.39-.24.63 0 .55.45 1 1 1h10c.55 0 1-.45 1-1 0-.24-.1-.46-.24-.63z`
}

const icon_caret_left = {
    title: 'caret-left',
    viewBox: '0 0 20 20',
    d: `M13 4c-.24 0-.46.1-.63.24l-.01-.01-6 5 .01.01c-.22.19-.37.45-.37.76s.15.57.37.76l-.01.01 6 5 .01-.01c.17.14.39.24.63.24.55 0 1-.45 1-1V5c0-.55-.45-1-1-1z`
}

const icon_caret_right = {
    title: 'caret-right',
    viewBox: '0 0 20 20',
    d: `M14 10c0-.31-.15-.57-.37-.76l.01-.01-6-5-.01.01C7.46 4.1 7.24 4 7 4c-.55 0-1 .45-1 1v10c0 .55.45 1 1 1 .24 0 .46-.1.63-.24l.01.01 6-5-.01-.01c.22-.19.37-.45.37-.76z`
}

const icon_arrow_down = {
    title: 'arrow-down',
    viewBox: '0 0 20 20',
    d: `M16 6c-.28 0-.53.11-.71.29L10 11.59l-5.29-5.3a1.003 1.003 0 0 0-1.42 1.42l6 6c.18.18.43.29.71.29s.53-.11.71-.29l6-6A1.003 1.003 0 0 0 16 6z`
}

const icon_arrow_up = {
    title: 'arrow-up',
    viewBox: '0 0 20 20',
    d: `M16.71 12.29l-6-6C10.53 6.11 10.28 6 10 6s-.53.11-.71.29l-6 6a1.003 1.003 0 0 0 1.42 1.42L10 8.41l5.29 5.29c.18.19.43.3.71.3a1.003 1.003 0 0 0 .71-1.71z`
}

const icon_arrow_left = {
    title: 'arrow-left',
    viewBox: '0 0 20 20',
    d: `M8.41 10l5.29-5.29c.19-.18.3-.43.3-.71a1.003 1.003 0 0 0-1.71-.71l-6 6c-.18.18-.29.43-.29.71 0 .28.11.53.29.71l6 6a1.003 1.003 0 0 0 1.42-1.42L8.41 10z`
}

const icon_arrow_right = {
    title: 'arrow-right',
    viewBox: '0 0 20 20',
    d: `M13.71 9.29l-6-6a1.003 1.003 0 0 0-1.42 1.42l5.3 5.29-5.29 5.29c-.19.18-.3.43-.3.71a1.003 1.003 0 0 0 1.71.71l6-6c.18-.18.29-.43.29-.71 0-.28-.11-.53-.29-.71z`
}

const icon_double_arrow_left = {
    title: 'double-arrow-left',
    viewBox: '0 0 20 20',
    d: `M5.41 10l5.29-5.29c.19-.18.3-.43.3-.71a1.003 1.003 0 0 0-1.71-.71l-6 6c-.18.18-.29.43-.29.71 0 .28.11.53.29.71l6 6a1.003 1.003 0 0 0 1.42-1.42L5.41 10zm6 0l5.29-5.29c.19-.18.3-.43.3-.71a1.003 1.003 0 0 0-1.71-.71l-6 6c-.18.18-.29.43-.29.71 0 .28.11.53.29.71l6 6a1.003 1.003 0 0 0 1.42-1.42L11.41 10z`
}

const icon_double_arrow_right = {
    title: 'double-arrow-right',
    viewBox: '0 0 20 20',
    d: `M11 10c0-.28-.11-.53-.29-.71l-6-6a1.003 1.003 0 0 0-1.42 1.42L8.59 10 3.3 15.29c-.19.18-.3.43-.3.71a1.003 1.003 0 0 0 1.71.71l6-6c.18-.18.29-.43.29-.71zm5.71-.71l-6-6a1.003 1.003 0 0 0-1.42 1.42l5.3 5.29-5.29 5.29c-.19.18-.3.43-.3.71a1.003 1.003 0 0 0 1.71.71l6-6c.18-.18.29-.43.29-.71 0-.28-.11-.53-.29-.71z`
}

export const icons = {
    code: icon_code,
    check: icon_check,
    close: icon_close,
    warn: icon_warn,
    'minus': icon_minus,
    'plus': icon_plus,
    'eye-off': icon_eye_off,
    'caret-down': icon_caret_down,
    'caret-up': icon_caret_up,
    'caret-left': icon_caret_left,
    'caret-right': icon_caret_right,
    'arrow-down': icon_arrow_down,
    'arrow-up': icon_arrow_up,
    'arrow-left': icon_arrow_left,
    'arrow-right': icon_arrow_right,
    'double-arrow-left': icon_double_arrow_left,
    'double-arrow-right': icon_double_arrow_right,
}

export const extendIcons = (key: string, desc: IconModel) => {
    if(icons[key]) {
        console.warn(`icon ${key} already existed, use another icon name instead. \n`)
    }
    icons[key] = desc
}
