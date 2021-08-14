import * as React from 'react'

export abstract class AbstractComponent<P, S> extends React.Component<P, S> {
    private timeoutIds = []

    protected constructor(props: P, context?: any) {
        super(props, context);
    }

    protected setTimeout(callback: () => void, timeout?: number) {
        const id = setTimeout(callback, timeout)
        this.timeoutIds.push(id)
        return () => clearTimeout(id)
    }

    protected clearTimeouts = () => {
        if(this.timeoutIds.length) {
            this.timeoutIds.forEach(id => clearTimeout(id))
        }
        this.timeoutIds.length = 0
    }

    public componentWillUnmount() {
        this.clearTimeouts()
    }
}
