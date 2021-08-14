const webpack = require('webpack');
const path = require('path');
const isDev = process.env.NODE_ENV !== 'production';

const plugins = [];
if(isDev) {
    plugins.push(new webpack.HotModuleReplacementPlugin())
}

module.exports = {
    entry : './demo/index.tsx',

    output: {
        filename  : 'bundle.js',
        path      : path.resolve(__dirname + '/dist'),
        publicPath: '/dist/',
    },

    devtool: 'source-map',

    devServer: {
        port              : 1234,
        historyApiFallback: true,
        inline            : true,
    },

    resolve: {
        extensions: ['.ts', '.tsx', '.js', '.json']
    },

    module : {
        rules: [
            {
                test  : /\.tsx?$/,
                loader: 'awesome-typescript-loader'
            },
            {
                test: /\.s?css$/,
                use : [{
                    loader: 'style-loader'
                }, {
                    loader: 'css-loader'
                }, {
                    loader: 'sass-loader'
                }]
            }
        ]
    },

    plugins: [
        ...plugins
    ],

    // externals: {
    //     'react'    : 'React',
    //     'react-dom': 'ReactDOM'
    // },
};
