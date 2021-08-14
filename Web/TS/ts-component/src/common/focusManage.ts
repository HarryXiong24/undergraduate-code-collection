import * as keys from './keys'
import {FOCUS_DISABLED_CLASS} from "./constants";
import {isUndefined} from "./utils";

export class DefaultFocusManage {
    protected isRunning: boolean = false

    protected isActive(): any {
        return true
    }

    protected start() {
        this.isRunning = true
    }

    protected stop(): any {
        this.isRunning = false
    }
}

export class FocusManage extends DefaultFocusManage {
    constructor(private contain: Element, private className: string) {
        super()
    }

    public isActive() {
        return this.isRunning
    }

    public start() {
        this.isRunning = true
        this.contain.addEventListener('mousedown', this.handleMouseDown)
    }

    public stop() {
        this.reset();
        this.isRunning = false;
    }

    private reset() {
        this.contain.classList.remove(this.className)
        this.contain.removeEventListener('mousedown', this.handleMouseDown)
        this.contain.removeEventListener('keydown', this.handleKeyDown)
    }

    private handleMouseDown = () => {
        this.reset()
        this.contain.classList.add(this.className)
        this.contain.addEventListener('keydown', this.handleKeyDown)
    }

    private handleKeyDown = (event: KeyboardEvent) => {
        if (event.which == keys.TAB) {
            this.reset()
            this.contain.addEventListener('mousedown', this.handleMouseDown)
        }
    }
}

export const focusManage = isUndefined(document) ? new DefaultFocusManage() : new FocusManage(document.documentElement, FOCUS_DISABLED_CLASS)
