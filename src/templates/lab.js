import { graphql } from 'gatsby'
import React from 'react'
import { Helmet } from 'react-helmet'
import { make as Lab } from '../../lib/js/re/pages/Lab'
import Layout from '../Layout'

export default ({ data }) => {
  return (
    <Layout>
      <Helmet>
        <title>Iteam | {data.ghostPost.title}</title>
      </Helmet>
      <Lab data={data.ghostPost} />
    </Layout>
  )
}

export const query = graphql`
  query Lab($slug: String!) {
    ghostPost(slug: { eq: $slug }) {
      feature_image
      html
      primary_author {
        bio
        name
        profile_image
      }
      primary_tag {
        name
      }
      published_at(formatString: "DD MMMM YYYY", locale: "sv-SE")
      slug
      title
    }
  }
`