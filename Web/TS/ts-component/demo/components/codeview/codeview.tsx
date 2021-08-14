import * as React from 'react'
import * as cn from 'classnames'
import Highlight from 'react-highlight'
import {IProps} from "../../../src/common/props";
import {Icon, Toaster, TypeKind} from "../../../src";
import {isUndefined, safeInvoke} from "../../../src/common/utils";

import './codeview.scss'
import 'highlight.js/styles/googlecode.css'
import 'highlight.js/lib/languages/javascript'

export interface ICodeViewProps extends IProps {
    lang?: string,
    code: string,
    expanded?: boolean,
    defaultExpanded?: boolean,
    onChange?: (expanded: boolean) => void
}

export interface ICodeViewState {
    expanded: boolean
}

export class CodeView extends React.Component<ICodeViewProps, ICodeViewState> {
    public static readonly displayName = 'CodeView'

    public static defaultProps = {
        lang: 'javascript',
        defaultExpanded: false
    }

    private toaster: Toaster

    constructor(props: ICodeViewProps, context?: any) {
        super(props, context);
        this.state = {
            expanded: isUndefined(this.props.expanded) ? this.props.defaultExpanded : this.props.expanded
        }
    }

    public componentWillReceiveProps(nextProps: ICodeViewProps) {
        if (!isUndefined(nextProps.expanded) && nextProps.expanded != this.state.expanded) {
            this.setState({expanded: nextProps.expanded})
        }
    }

    private handleClick = () => {
        if (isUndefined(this.props.expanded)) {
            this.setState(state => ({expanded: !state.expanded}))
        } else {
            safeInvoke(this.props.onChange, this.state.expanded)
        }
    }

    private static execCopy(text) {
        // remain format
        const input = document.createElement('textarea')
        input.value = text
        document.body.appendChild(input)
        input.select()
        document.execCommand('copy')
        document.body.removeChild(input)
    }

    private handleCopy = () => {
        CodeView.execCopy(this.props.code)
        if(isUndefined(this.toaster)) {
            this.toaster = Toaster.create()
        }
        this.toaster.show({
            message: '已复制至剪贴板',
            showDismissButton: true,
            type: TypeKind.SUCCESS,
        })
    }

    public render() {
        const codeViewClasses = cn('code-view', {
            'code-view-expanded': this.state.expanded
        }, this.props.className)
        return (
            <figure className={codeViewClasses}>
                <div className="operator-list">
                    <span className="operator-item" onClick={this.handleCopy}>
                        Copy
                    </span>
                    <span className="operator-item" onClick={this.handleClick}>
                        Hide
                    </span>
                </div>
                <Highlight language={this.props.lang}>{this.props.code}</Highlight>
                {!this.state.expanded &&
                <span className="show-code" onClick={this.handleClick}>
                    <Icon name="code"/> Show code
                </span>}
                {this.state.expanded &&
                <span className="hide-code" onClick={this.handleClick}>
                    <Icon name="eye-off"/> Hide code
                </span>}
            </figure>
        )
    }
}
