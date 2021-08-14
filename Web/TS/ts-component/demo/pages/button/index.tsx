import * as React from 'react'
import Demo from './button'
import {CodeView} from "../../components/codeview/codeview";

// @ts-ignore
const code = require('!!raw-loader!./button')

export default () => {
    return (
        <div>
            <Demo/>
            <CodeView code={code}/>
        </div>
    )
}
