import * as React from 'react'
import Demo from './collapse'
import {CodeView} from "../../components/codeview/codeview";

// @ts-ignore
const code = require('!!raw-loader!./collapse')

export default () => {
    return (
        <div>
            <Demo/>
            <CodeView code={code}/>
        </div>
    )
}
